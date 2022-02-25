#include <stdio.h>
#include <stdlib.h>
 
/* 定义WORD为两个字节的类型 */
typedef unsigned short WORD;
/* 定义DWORD为四个字节的类型 */
typedef unsigned long DWORD;
 
/* 位图文件头主要是对位图文件的一些描述 位图信息头主要是对位图图像方面信息的描述 */
/*************************** 位图标准信息(54字节) ******************************************/
/* 位图文件头 （位图头的字节数 = 位图文件字节数 - 位图图像数据字节数）*/
typedef struct tagBITMAPFILEHEADER {
  unsigned short bfType;   // 19778，必须是BM字符串，对应的十六进制为0x4d42,十进制为19778
  unsigned int bfSize;    // 文件大小
  unsigned short bfReserved1; // 一般为0
  unsigned short bfReserved2; // 一般为0
  unsigned int bfOffBits;   // 从文件头到像素数据的偏移，也就是这两
} BITMAPFILEHEADER;
 
/* 位图信息头 */
typedef struct tagBITMAPINFOHEADER {
  unsigned int biSize;    // 此结构体的大小
  int biWidth;        // 图像的宽
  int biHeight;        // 图像的高
  unsigned short biPlanes;  // 1
  unsigned short biBitCount; // 一像素所占的位数，一般为24
  unsigned int biCompression; // 0
  unsigned int biSizeImage;  // 像素数据所占大小, 这个值应该等于上面文件头结构中bfSize-bfOffBits
  int biXPelsPerMeter;    // 0
  int biYPelsPerMeter;    // 0
  unsigned int biClrUsed;   // 0 
  unsigned int biClrImportant;// 0
} BITMAPINFOHEADER;
 
/* 彩色表:调色板 */
typedef struct RGB_QUAD 
{
	WORD rgbBlue;     // 蓝色强度 
	WORD rgbGreen;    // 绿色强度 
	WORD rgbRed;      // 红色强度 
	WORD rgbReversed; // 保留值 
} RGBQUAD;
 
 
int main()
{
	int i = sizeof(BITMAPFILEHEADER);
	int j = sizeof(long);
	FILE *fp;                     // 定义一个文件指针
	BITMAPFILEHEADER bmpFileHeader;  // 定义一个 BMP 文件头的结构体
    #pragma pack(1);
	BITMAPINFOHEADER bmpInfo;               // 定义一个 BMP 文件信息结构体 
 
 
	// "rb" 只读打开一个二进制文件，只允许读数据。'b'指的是让这个库函数以二进制形式打开此文件。
	// 读取失败会返回空指针，读取成功后，fp 会指向一块具有 bmp 属性的内存,我们可以对这块内存开始操作
	if((fp = fopen("d:/1.bmp", "rb")) == NULL) // fp = 0x00426aa0
	{
		printf("Cann't open the file!\n");
		return 0;
	}
 
	// 让 fp 指向 bmp 文件的开始 
	// 第 2 个参数是偏移量 第三个参数是文件起始地址 所以此函数执行成功后文件指针会指向文件的开始
	fseek(fp, 0, SEEK_SET);                            // fp = 0x00426aa0
 
	// 读取文件信息
	/*
		参数1: 读出数据的存放缓冲区
		参数2: 读取多少个字节的数据
		参数3: 读取几包这样的数据
		参数4: 文件指针（源数据）
	*/
	fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, fp); 
	
	fread(&bmpInfo, sizeof(bmpInfo), 1, fp);
 
 
	// 输出BMP文件的位图文件头的所有信息
	printf("位图文件头主要是对位图文件的一些描述:BMPFileHeader\n\n");
	printf("文件标识符 = 0X%X\n", bmpFileHeader.bfType);
	printf("BMP 文件大小 = %d 字节\n", bmpFileHeader.bfSize);
	printf("保留值1 = %d \n", bmpFileHeader.bfReserved1);
	printf("保留值2 = %d \n", bmpFileHeader.bfReserved2);
	printf("文件头的最后到图像数据位开始的偏移量 = %d 字节\n", bmpFileHeader.bfOffBits);
 
	// 输出BMP文件的位图信息头的所有信息
	printf("\n\n位图信息头主要是对位图图像方面信息的描述:BMPInfo\n\n");
	printf("信息头的大小 = %d 字节\n", bmpInfo.biSize);
	printf("位图的高度 = %d \n", bmpInfo.biHeight);
	printf("位图的宽度 = %d \n", bmpInfo.biWidth);
	printf("图像的位面数(位面数是调色板的数量,默认为1个调色板) = %d \n", bmpInfo.biPlanes); 
	printf("每个像素的位数 = %d 位\n", bmpInfo.biBitCount);
	printf("压缩类型 = %d \n", bmpInfo.biCompression);
	printf("图像的大小 = %d 字节\n", bmpInfo.biSizeImage);
	printf("水平分辨率 = %d \n", bmpInfo.biXPelsPerMeter);
	printf("垂直分辨率 = %d \n", bmpInfo.biYPelsPerMeter);
	printf("使用的色彩数 = %d \n", bmpInfo.biClrUsed);
	printf("重要的色彩数 = %d \n", bmpInfo.biClrImportant);
 
	printf("\n\n\n压缩说明：有0（不压缩），1（RLE 8，8位RLE压缩），2（RLE 4，4位RLE压缩，3（Bitfields，位域存放）");
 
	fclose(fp);
 
	while(1);
 
	return 0;
 
}