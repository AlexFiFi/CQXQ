#pragma once
#include <iostream>
#include <vector>
#include <string>

//��ӡ�ڴ�����
static void show(void* t, const int len)
{
	auto* const p = static_cast<unsigned char*>(t);
	std::cout << "{";
	for (auto i = 0; i < len; ++i)
	{
		std::cout << static_cast<int>(p[i]);
		if (i != len - 1)std::cout << ", ";
	}
	std::cout << "}" << std::endl;
}

//�ڴ淭ת
static unsigned char* Flip(unsigned char* const str, int len) noexcept
{
	auto f = 0;
	--len;
	while (f < len)
	{
		const auto p = str[len];
		str[len] = str[f];
		str[f] = p;
		++f;
		--len;
	}
	return str;
}

//���ֽڼ�...
//��ԭ�е����ݻ����ϲ���
template <typename ClassType>
unsigned char* toBin(ClassType& i) noexcept
{
	return Flip(reinterpret_cast<unsigned char*>(&i), sizeof(ClassType));
}


class Unpack final
{
	std::vector<unsigned char> buff;
public:
	Unpack() noexcept;
	explicit Unpack(const char*);
	explicit Unpack(std::vector<unsigned char>) noexcept;
	explicit Unpack(const std::string&);

	Unpack& setData(const char* i, int len);
	Unpack& clear() noexcept;
	[[nodiscard]] int len() const noexcept;

	Unpack& add(int i); //���һ������
	int getInt() noexcept; //����һ������

	Unpack& add(long long i); //���һ��������
	long long getLong() noexcept; //����һ��������

	Unpack& add(short i); //���һ��������
	short getshort() noexcept; //����һ��������

	Unpack& add(const unsigned char* i, short len); //���һ���ֽڼ�(����add(std::string i);)
	std::vector<unsigned char> getchars() noexcept; //����һ���ֽڼ�(����getstring();)

	Unpack& add(std::string i); //���һ���ַ���
	std::string getstring(); //����һ���ַ���

	Unpack& add(Unpack& i); //���һ��Unpack
	Unpack getUnpack() noexcept; //����һ��Unpack

	std::string getAll() noexcept; //���ر�������

	void show();
};
