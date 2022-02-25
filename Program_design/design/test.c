#include <stdio.h>
#define UINT unsigned int
#define DWORD unsigned long
#define LONG long
#define WORD unsigned short  
#define BYTE char
typedef struct tagBITMAPFILEHEADER { /* bmfh */
	UINT bfType;
	DWORD bfSize;
	UINT bfReserved1;
	UINT bfReserved2;
	DWORD bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER { /* bmih */
	DWORD biSize;
	LONG biWidth;
	LONG biHeight;
	WORD biPlanes;
	WORD biBitCount;//每个像素的位数
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD { /* rgbq */
BYTE rgbBlue;
BYTE rgbGreen;
BYTE rgbRed;
BYTE rgbReserved;
} RGBQUAD;

typedef struct tagBITMAPINFO { /* bmi */
	BITMAPINFOHEADER bmiHeader;
	RGBQUAD bmiColors[1];
} BITMAPINFO;

int main()
{
	FILE *r_file, *w_file;
	char *r_filename = "d:/1.bmp";
	char *w_filename = "d:/2.bmp";
	
	BITMAPFILEHEADER bmfh;
	BITMAPINFO bmi;
	char r_buf[8];
	int count, i;
	if((r_file = fopen(r_filename,"rb")) == NULL)
	{
		printf("READ FILE %s FAIL./n",r_filename);
		return 1;
	}
	if((w_file = fopen(w_filename,"wb")) == NULL)
	{
		printf("READ FILE %s FAIL./n",w_filename);
		return 1;
	}
	
	fseek(r_file,0,SEEK_SET);
	fread(&bmfh,sizeof(BITMAPFILEHEADER),1,r_file);	
	fread(&bmi,sizeof(BITMAPINFO),1,r_file);
	fwrite(&bmfh,sizeof(BITMAPFILEHEADER),1,w_file);
	fwrite(&bmi,sizeof(BITMAPINFO),1,w_file);
	while(1)
	{
		if((count = fread(r_buf, sizeof(char), 8, r_file)) != 0)
		{
			for(i=0 ; i < count; i++)
			{
				r_buf[i] ^= 0xabcd;
			}
			fwrite(r_buf, sizeof(char), 8, w_file);
		}
		else
		{
			break;
		}
	}
	fclose(r_file);
	fclose(w_file);
	return 0;
}