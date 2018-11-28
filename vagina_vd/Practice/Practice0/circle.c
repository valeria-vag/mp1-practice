#include <stdio.h> 
#include <math.h> 

void main() 
{
	double x1, x2, y1, y2, r1, r2, d, r_m, r_b;
	printf("vvedite koordinaty centra 1-y okruzhnosti");
	scanf("%lf %lf", &x1, &y1);
	printf("vvedite radius 1-y okruzhnosti");
	scanf("%lf", &r1);
	printf("vvedite koordinaty centra 2-y okruzhnosti");
	scanf("%lf %lf", &x2, &y2);
	printf("vvedite radius 2-y okruzhnosti");
	scanf("%lf", &r2);
	if (r1 <= 0 || r2 <= 0)
	{
		printf("Nekorrektny vvod radiusa. Vvedite polozhitelnoe chislo.");
		return 0;
	}
	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (r1 == r2 && d == 0) 
	{
		printf("Okruzhnosti sovpadayut i imeyut beskonechno mnogo obshih tochek");
		return 0;
	}
	if (d == r1 + r2)
	{
		printf("Okruzhnosti kasayutsa vneshnim obrazom i imeyut 1 obshuyu tochku");
		return;
	}
	if (d > r1 + r2)
	{
		printf("Okruzhnosti udaleny drug ot druga i ne imeyut obshih tochek");
		return;
	}
	if (r1 != r2)
	{
		if (r1 > r2)
		{
			r_b = r1;
			r_m = r2;
		}
		else
		{
			r_b = r2;
			r_m = r1;
		}
	}
	if (r1 != r2 && d == r_b - r_m)
	{
		printf("Okruzhnosti kasayutsa vnutrennim obrazom i imeyut 1 obshuyu tochku");
		return;
	}
	if (r1 != r2 && d >= 0 && d < r_b - r_m)
	{
		printf("Odna okruzhnost lezhit vnutri drugoy. Obshih tochek net");
		return;
	}
	printf("Okruzhnosti imeyut 2 obshih tochki");
	return;
}
