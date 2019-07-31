//	https://stackoverflow.com/questions/33814916/openssl-c-rsa-sign-is-different-from-command-line-sign
//	https://stackoverflow.com/questions/11886262/reading-public-private-key-from-memory-with-openssl
//	echo "hola" | openssl rsautl -pkcs -sign -inkey key.pem > sign.txt

#include "pch.h"
#include <openssl/sha.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/bio.h>


const std::string message = "100dangun1001jjzhaogame@163.com";

/*constexpr*/ char g_hexmap[] = {
	'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

std::string hex_2_str(unsigned char *data, int len)
{
	std::string s(len * 2, ' ');
	for (int i = 0; i < len; ++i) {
		s[2 * i]		= g_hexmap[(data[i] & 0xF0) >> 4];
		s[2 * i + 1]	= g_hexmap[data[i] & 0x0F];
	}
	return s;
}


int main()
{
//	std::ifstream infile("_prvkey_xxxx.pem", std::ios::binary);
	std::ifstream infile("_prvkey_xxxx.pem");

	RSA *rsaPrivKey = nullptr;
	{	// https://stackoverflow.com/questions/15138353/how-to-read-a-binary-file-into-a-vector-of-unsigned-chars

		std::ifstream infile("_prvkey1.pem", std::ios::binary);
		if (infile.good() == false)
		{
			return 0;
		}

		// Stop eating new lines in binary mode!!!
		infile.unsetf(std::ios::skipws);

		// get its size:
		std::streampos fileSize;

		infile.seekg(0, std::ios::end);
		fileSize = infile.tellg();
		infile.seekg(0, std::ios::beg);

		// reserve capacity
		std::vector<unsigned char> private_key_vec;
		private_key_vec.reserve(fileSize);

		// read the data:
		private_key_vec.insert(
			private_key_vec.begin(),
			std::istream_iterator<unsigned char>(infile),
			std::istream_iterator<unsigned char>()
		);

		BIO *bufio = BIO_new_mem_buf(reinterpret_cast<const void*>(private_key_vec.data()), static_cast<int>(private_key_vec.size()));
		PEM_read_bio_RSAPrivateKey(bufio, &rsaPrivKey, NULL, NULL);
	}

	unsigned char encrypted[4098] = {};
	unsigned int outlen;

	unsigned char hash[20];

	if (!SHA1(reinterpret_cast<const unsigned char*>(message.c_str()), message.length(), hash)) {
		printf("SHA1 failed\n");
		return 0;
	}
	if (!RSA_sign(NID_sha1, hash, 20, encrypted, &outlen, rsaPrivKey)) {
		printf("RSA_sign failed\n");
		return 0;
	}

	std::string signature = hex_2_str(encrypted, outlen);

	std::cout << "signature (" << outlen << ") :" << signature << std::endl;

	return 0;
}

