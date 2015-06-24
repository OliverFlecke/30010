#ifndef LEVEL_H
#define LEVEL_H

#define NUMBEROFLEVELS 10

// Functions
void loadLevelFromROM(long rom *src, long *dest);

/*
	The array of all our levels. 
*/
rom long levelROM[][32] = 
{
	{
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000004000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000
	},
	// Humans/Aliens
	{
		0x000000000, 0x002A002A0, 0x002E002E0, 0x022A002A0, 
		0x012A00080, 0x010800958, 0x015550040, 0x000410150, 
		0x000410150, 0x000420150, 0x000400554, 0x005540554, 
		0x004040554, 0x004040554, 0x004040220, 0x004040220, 
		0x014050514, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000
	},

	{	// Starter level
		0x000000000, 0x000000000, 0x02AAAAAA8, 0x015555554, 
		0x000000000, 0x000000000, 0x00003C000, 0x000000000, 
		0x00FF00FF0, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000
	},

	// Space invader
	{
		0x000200800, 0x000200800, 0x000082000, 0x000082000, 
		0x000155400, 0x000155400, 0x000555500, 0x0005D7500, 
		0x0015D7540, 0x001555540, 0x005555550, 0x005555550, 
		0x005555550, 0x0057FFD50, 0x005555550, 0x004855210, 
		0x004800210, 0x004A00A10, 0x004200810, 0x000200800, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000
	},


	{	// Happy smiley
		0x000000000, 0x000028000, 0x000096000, 0x000096000, 
		0x000255800, 0x000255800, 0x000955600, 0x0009D7600, 
		0x0025D7580, 0x002555580, 0x00957D560, 0x00957D560, 
		0x009555560, 0x009555560, 0x002755D80, 0x0025FF580, 
		0x00097D600, 0x000955600, 0x000255800, 0x000255800, 
		0x000096000, 0x000096000, 0x000028000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000
	},

	{	// Angry smiley
		0x000000000, 0x000028000, 0x000096000, 0x000296800, 
		0x000255800, 0x000A55A00, 0x000955600, 0x002555580, 
		0x0027D7D80, 0x002555580, 0x00257D580, 0x002555580, 
		0x00257D580, 0x0025D7580, 0x002755D80, 0x002555580, 
		0x000955600, 0x000955600, 0x000255800, 0x000255800, 
		0x000296800, 0x000096000, 0x000028000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000
	}, 

	// Circle 
	{ 
		0x0F400001F, 0x0D0014007, 0x040069001, 0x000182400, 
		0x000614900, 0x001869240, 0x006182490, 0x018614924, 
		0x06187D249, 0x06187D249, 0x018614924, 0x006182490, 
		0x001869240, 0x000614900, 0x000182400, 0x000069000, 
		0x000014000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000
	},

	// Clown
	{
		0x000000000, 0x000055000, 0x000155400, 0x000555500, 
		0x001555540, 0x001A55A40, 0x001A96A40, 0x001B96E40, 
		0x001A96A40, 0x001669940, 0x001569540, 0x001569540, 
		0x000555500, 0x000655900, 0x0006AA900, 0x0006FF900, 
		0x0005AA500, 0x000155400, 0x000055000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000
	},

	// Heart
	{
		0x000000000, 0x000000000, 0x000400100, 0x001500540, 
		0x001500540, 0x001541540, 0x001541540, 0x001555540, 
		0x001555540, 0x001555540, 0x001555540, 0x000555500, 
		0x000555500, 0x000555500, 0x000155400, 0x000155400, 
		0x000155400, 0x000055000, 0x000055000, 0x000055000, 
		0x000014000, 0x000014000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000
	},

	// House
	{
		0x000000000, 0x000000000, 0x000328000, 0x000328000, 
		0x0003AA000, 0x0003AA000, 0x0002AA800, 0x0002AA800, 
		0x000AAAA00, 0x000AAAA00, 0x000555500, 0x000555500, 
		0x0007D7D00, 0x0007D7D00, 0x0007D7D00, 0x0007D7D00, 
		0x000557D00, 0x000557D00, 0x000557D00, 0x000557D00, 
		0x000557D00, 0x000557D00, 0x000555500, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000
	},

	// Hardcore level
	{
		0x05A6969A5, 0x069A41A69, 0x0A690069A, 0x09A4001A6, 
		0x069000069, 0x0A400001A, 0x090000006, 0x040000001, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x040000001, 0x090000006, 0x064014019, 0x0D903C067, 
		0x0D9000067, 0x064000019, 0x090000006, 0x040000001, 
		0x000000000, 0x000000000, 0x000000000, 0x000000000, 
		0x000000000, 0x0AAAAAAAA, 0x055555555, 0x055555555
	}

};

#endif