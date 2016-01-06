/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include <string.h>

int check(char *dob)
{
	int a[10], d = 0, e, f, g, i, b = 0, q = 0, x = 0, sp[20], t = 0, s = 0;
	for (i = 0; i < 8; i++)
		a[i] = 0;
	for (i = 0; dob[i] != '\0'; i++)
	{
		if (dob[i] >= '0' && dob[i] <= '9')
		{
			a[b] = (int)dob[i] - 48;
			b++;
		}
		else
		{
			sp[t] = i;
			x = x + 1;
			t++;
		}
	}
	if (sp[0] == 2 && sp[1] == 5)
	{
		e = a[0] * 10 + a[1];
		f = a[2] * 10 + a[3];
		g = a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7];
		if (b < 8 || b>8)
			return(1);
	}
	else if (sp[0] == 1 && sp[1] == 4)
	{
		e = a[0];
		f = a[1] * 10 + a[2];
		g = a[3] * 1000 + a[4] * 100 + a[5] * 10 + a[6];
		if (b < 7 || b>7)
			return(1);
	}
	else if (sp[0] == 2 && sp[1] == 4)
	{
		e = a[0] * 10 + a[1];
		f = a[2];
		g = a[3] * 1000 + a[4] * 100 + a[5] * 10 + a[6];
		if (b < 7 || b>7)
			return(1);
	}
	else if (sp[0] == 1 && sp[1] == 3)
	{
		e = a[0];
		f = a[1];
		g = a[2] * 1000 + a[3] * 100 + a[4] * 10 + a[5];
		if (b < 6 || b>6)
			return(1);
	}
	switch (f)
	{
	case 1:if (e > 31) s = 1; break;	// e gives date f gives month g gives year
	case 2:if (e > 28) s = 1;; break;
	case 3:if (e > 31) s = 1; break;
	case 4:if (e > 30) s = 1; break;
	case 5:if (e > 31) s = 1; break;
	case 6:if (e > 30) s = 1; break;
	case 7:if (e > 31) s = 1; break;
	case 8:if (e > 31)s = 1; break;
	case 9:if (e > 30)s = 1; break;
	case 10:if (e > 31) s = 1; break;
	case 11:if (e > 30) s = 1; break;
	case 12:if (e > 31) s = 1; break;
	default:s = 1;
	};
	if ((((g % 4 == 0) && (g % 100 != 0)) || (g % 400 == 0)) && (e == 29))	//leap year condition
		s = 0;
	if ((g != 0) && (s != 1) && (x == 2) && (e != 0) && (f != 0))
		return(0);
	else
		return(1);

}
int conv(char *dob1)
{
	int x = 0, i = 0;
	for (i = 0; dob1[i] != '\0'; i++)
	{
		x = x + 1;
	}
	return x;

}
int checkd(char *dob1, char *dob2)
{
	int i;
	for (i = 0; i < 2; i++)
	{
		if (dob1[i]>dob2[i])
			return 2;
		else if (dob1[i] < dob2[i])
			return 1;
	}
	return 3;
}
int checkm(char *dob1, char *dob2, int len, int len2)
{
	int i;
	for (i = 3; i < 5; i++)
	{
		if (dob1[i]>dob2[i])
			return 2;
		else if (dob1[i]<dob2[i])
			return 1;
	}
	return 3;
}
int checky(char *dob1, char *dob2, int len, int len2)
{
	int i;
	for (i = len - 5; i < len; i++)
	{
		if (dob1[i]>dob2[i])
		{
			return 2;	//2 is bigger
		}
		else if (dob1[i] < dob2[i])
			return 1; //1 is bigger
	}
	return 3;
}
int isOlder(char *dob1, char *dob2) {
	int a, b, i = 0, j = 0, len1, len2, count = 0, x, y, z, max = 0;
	len1 = conv(dob1);
	len2 = conv(dob2);
	a = check(dob1);
	b = check(dob2);
	if (a == 0 && b == 0)
	{
		x = checky(dob1, dob2, len1, len2);
		if (x == 2)
			return 2;
		else if (x == 1)
			return 1;
		else if (x == 3)
		{
			y = checkm(dob1, dob2, len1, len2);
			if (y == 2)
				return 2;
			else if (y == 1)
				return 1;
			else if (y == 3)
			{
				z = checkd(dob1, dob2);
				if (z == 2)
					return 2;
				else if (z == 1)
					return 1;
				else if (z == 3)
					return 0;
			}
		}
	}
	else
		return -1;
}

