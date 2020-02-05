
#include "stdafx.h"
#include <vector>
#include <algorithm>

enum imagetype
{
	eRGBA32,
	eARGB32,
	eBGRA32,
	eABGR32
};

class BaseProcess {
public:
	virtual int Process(unsigned int * pixelhead)
	{
		return 0;
	}
};
template<imagetype T, int R, int G, int B, int A>
class DecodePremultipliedColor :public BaseProcess
{
public:
	DecodePremultipliedColor() {}
	virtual int Process(unsigned int * pixelhead)
	{
		unsigned char* pixel = (unsigned char*)pixelhead;
		char a = (char)pixel[A];
		char r = (char)pixel[R];
		char g = (char)pixel[G];
		char b = (char)pixel[B];
		if (a == 0)
		{
			return 0;
		}
		pixel[R] = r * 255 / a;
		pixel[G] = g * 255 / a;
		pixel[B] = b * 255 / a;
		return 0;
	}
};
typedef DecodePremultipliedColor<eRGBA32, 0, 1, 2, 3>  RGBA32Premultiplied;
typedef DecodePremultipliedColor<eABGR32, 3, 2, 1, 0>  ABGR32Premultiplied;
typedef DecodePremultipliedColor<eBGRA32, 2, 1, 0, 3>  BGRA32Premultiplied;
typedef DecodePremultipliedColor<eARGB32, 1, 2, 3, 0>  ARGB32Premultiplied;

int Process(imagetype type, unsigned int* pixel);
//int main()
//{
//	//模板调用
//	imagetype type = eRGBA32;
//	BaseProcess * pProcess = 0;
//	switch (type)
//	{
//	case eRGBA32:pProcess = new RGBA32Premultiplied(); break;
//	case eARGB32:pProcess = new ARGB32Premultiplied(); break;
//	case eBGRA32:pProcess = new BGRA32Premultiplied(); break;
//	case eABGR32:pProcess = new ABGR32Premultiplied(); break;
//	default:
//		break;
//	}
//	unsigned int g = 0xff343433;
//	pProcess->Process(&g);
//	//直接函数调用
//	Process(type, &g);
//}

int Process(imagetype type, unsigned int* pixelhead)
{
	int R = 0, G = 0, B = 0, A = 0;
	switch (type)
	{
	case eRGBA32:
		R = 0;
		G = 1;
		B = 2;
		A = 3;
		break;
	case eARGB32:
		R = 3;
		G = 2;
		B = 1;
		A = 0;
		break;
	case eBGRA32:
		R = 2;
		G = 1;
		B = 0;
		A = 3;
		break;
	case eABGR32:
		R = 1;
		G = 2;
		B = 3;
		A = 0;
		break;
	default:
		break;
	}
	unsigned char* pixel = (unsigned char*)pixelhead;
	char a = (char)pixel[A];
	char r = (char)pixel[R];
	char g = (char)pixel[G];
	char b = (char)pixel[B];
	if (a == 0)
	{
		return 0;
	}
	pixel[R] = r * 255 / a;
	pixel[G] = g * 255 / a;
	pixel[B] = b * 255 / a;
	return 0;
}