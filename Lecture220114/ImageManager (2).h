#pragma once
#include "SingletonBase.h"
#include "Image.h"

/*
�Լ� �����ε���
 - typedef �� ��ȣ�� �ڷ��� ��뿡 ������ ��
 - �Լ� �����ε� ��Ģ ����

 STL map 
 - ù ��° ��(first) : key
 - �� ���� ��(second) : value
 - insert�� �̿��ؼ� �߰�, key value �ΰ��� ���ÿ� �߰��ؾ� �ϱ� ������
   make_pair Ȥ�� pair�� �̿��ؼ� �߰��ؾ� �Ѵ�.

- pair() : �� ���� �ڷ����� �ϳ��� ���� �Լ�
- make_pair() : pair�� ������ִ� �Լ�
	p = make_pair(x, y);  [p = map�� ����]

- �ϳ��� Ű�� ���� ���� ���� �����ϰ� ������ <multimap> ���
- pair ��ü�� Ȯ����� ����ϰ� ������ <tuple> ���
*/
class ImageManager : public SingletonBase <ImageManager> {
private:
	//map �̹��� ���, �ݺ���
	typedef map<string, Image*> mapImageList;
	typedef map<string, Image*>::iterator mapImageIter;

	mapImageList _mImageList;

public:
	HRESULT init();
	void release();

	Image* addImage(string strKey, int width, int height);
	Image* addImage(string strKey, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	Image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	Image* addFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	Image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	Image* findImage(string strKey);
	bool deleteImage(string strKey);
	bool deleteAll();

	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	void resizeRender(string strKey, HDC hdc, int destX, int destY, int width, int height);

	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);

	ImageManager() {}
	~ImageManager() {}
};

