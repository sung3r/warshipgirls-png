#include <iostream>
#include "Files.h"
#include "Encrypt.h"


int main()
{
	// ������Կ
	aes_key key = { 0 };
	std::cout << "������16λ��Կ��" << std::endl;
	std::cin.get((char *)&key[0], key.size());

	// Ѱ������pngͼƬ
	std::vector<std::string> pngfiles;
	auto all_files = path::walk(path::curdir());
	for (auto filename : all_files)
	{
		if (path::splitext(filename)[1] == ".png")
		{
			pngfiles.push_back(filename);
		}
	}

	// ȡ���·��
	auto absolute_path = path::curdir() + "\\";
	for (auto &filename : pngfiles)
	{
		filename = filename.substr(absolute_path.size(), filename.size());
	}

	std::cout << "���ڼ�����..." << std::endl;

	// ͼƬ���ܲ���
	EncryptPNG(pngfiles, key);

	system("pause");

	return 0;
}