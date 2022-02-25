#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

int main()
{
	BITMAPFILEHEADER bmpFileHeader;
	BITMAPINFOHEADER bmpInfoHeader;
	RGBQUAD bmpColorTable[256];
	BYTE bmpValue[512 * 512];
	FILE *fp;

	fp = fopen("d:/1.bmp", "rb");
	fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, fp);//读入
	fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);
	fread(bmpColorTable, sizeof(RGBQUAD), 256, fp);
	fread(bmpValue, 1, 512 * 512, fp);	
	
	//将图像灰度值存入一位数组中
	int grayValue[512 * 512] = { 0 };
	for (int i = 0; i < 512 * 512; i++)
	{
		grayValue[i] = bmpColorTable[bmpValue[i]].rgbBlue;
	}

	//直方图
	int grayCount[256] = { 0 };
	double grayFrequency[256] = { 0.0 };
	for (int i = 0; i < 512 * 512; i++)
	{
		grayCount[grayValue[i]]++;
	}
	for (int i = 0; i < 256; i++){
		if (grayCount[i]){
			grayFrequency[i] = grayCount[i] / (512.0*512.0);
			printf("灰度值:%3d 频数:%6d 频率:%f\n", i, grayCount[i], grayFrequency[i]);
		}	
	}

	//最大值
	int grayMax = 0;
	for (int i = 0; i < 256; i++){
		if (grayCount[i] && (i > grayMax)){
			grayMax = i;
		}
	}
	printf("最大灰度值: %d\n", grayMax);

	//最小值
	int grayMin = 255;
	for (int i = 0; i < 256; i++){
		if (grayCount[i] && (i < grayMin)){
			grayMin = i;
		}
	}
	printf("最小灰度值: %d\n", grayMin);
  

	printf("文件大小: %d 字节\n", bmpFileHeader.bfSize);

	printf("图像的宽度: %d\n", bmpInfoHeader.biWidth);
	printf("图像的高度: %d\n", bmpInfoHeader.biHeight);
	printf("每个像素的位数: %d\n", bmpInfoHeader.biBitCount);
	printf("调色板中实际使用的颜色数: %d\n", bmpInfoHeader.biClrUsed	);
	printf("现实位图时必须使用的颜色数: %d\n", bmpInfoHeader.biClrImportant);
	fclose(fp);
	return 0;

}