// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF



// SSD1331 Commands
#define SSD1331_CMD_DRAWLINE 		    0x21
#define SSD1331_CMD_DRAWRECT 		    0x22
#define SSD1331_CMD_FILL 			      0x26
#define SSD1331_CMD_SETCOLUMN 		  0x15
#define SSD1331_CMD_SETROW    		  0x75
#define SSD1331_CMD_CONTRASTA 		  0x81
#define SSD1331_CMD_CONTRASTB 		  0x82
#define SSD1331_CMD_CONTRASTC		    0x83
#define SSD1331_CMD_MASTERCURRENT 	0x87
#define SSD1331_CMD_SETREMAP 		    0xA0
#define SSD1331_CMD_STARTLINE 		  0xA1
#define SSD1331_CMD_DISPLAYOFFSET 	0xA2
#define SSD1331_CMD_NORMALDISPLAY 	0xA4
#define SSD1331_CMD_DISPLAYALLON  	0xA5
#define SSD1331_CMD_DISPLAYALLOFF 	0xA6
#define SSD1331_CMD_INVERTDISPLAY 	0xA7
#define SSD1331_CMD_SETMULTIPLEX  	0xA8
#define SSD1331_CMD_SETMASTER 		  0xAD
#define SSD1331_CMD_DISPLAYOFF 		  0xAE
#define SSD1331_CMD_DISPLAYON     	0xAF
#define SSD1331_CMD_POWERMODE 		  0xB0
#define SSD1331_CMD_PRECHARGE 		  0xB1
#define SSD1331_CMD_CLOCKDIV 		    0xB3
#define SSD1331_CMD_PRECHARGEA 		  0x8A
#define SSD1331_CMD_PRECHARGEB 		  0x8B
#define SSD1331_CMD_PRECHARGEC 		  0x8C
#define SSD1331_CMD_PRECHARGELEVEL 	0xBB
#define SSD1331_CMD_VCOMH 			    0xBE 

// enhanced constants & commands added by SEMU
#define SSD1331_CMD_COPY            0x23
#define SSD1331_CMD_DIM             0x24
#define SSD1331_CMD_CLEAR           0x25
#define SSD1331_FILL_OFF            0x00
#define SSD1331_FILL_ON             0x01
#define SSD1331_CMD_SETGRAYSCALE	  0xB8
#define SSD1331_CMD_RESETGRAYSCALE	0xB9

#define SSD1331_CMD_SETSCROLL       0x27
#define SSD1331_CMD_SCROLLOFF       0x2E
#define SSD1331_CMD_SCROLLON        0x2F