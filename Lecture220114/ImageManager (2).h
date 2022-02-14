#pragma once
#include "SingletonBase.h"
#include "Image.h"

/*
함수 오버로딩시
 - typedef 등 모호한 자료형 사용에 주의할 것
 - 함수 오버로딩 규칙 참고

 STL map 
 - 첫 번째 값(first) : key
 - 두 번쨰 값(second) : value
 - insert를 이용해서 추가, key value 두개를 동시에 추가해야 하기 때문에
   make_pair 혹은 pair를 이용해서 추가해야 한다.

- pair() : 두 가지 자료형을 하나로 묶는 함수
- make_pair() : pair로 만들어주는 함수
	p = make_pair(x, y);  [p = map의 원소]

- 하나의 키에 여러 개의 값을 저장하고 싶으면 <multimap> 사용
- pair 자체를 확장시켜 사용하고 싶으면 <tuple> 사용
*/
class ImageManager : public SingletonBase <ImageManager> {
private:
	//map 이미지 목록, 반복자
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

