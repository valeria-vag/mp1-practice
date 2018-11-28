#include <stdio.h> 
#include <math.h> 

void main()
{
	double h, d, w, p_dvp, p_dsp, p_der, t_dvp, t_dsp, t_der, M, m_zst, m_bok, m_dv, m_kr, m_p;
	int k;
	printf("Vvedite plotnost dereva v kg/m^3 \n");
	scanf("%lf", &p_der);
	if (p_der <= 0)
	{
		printf("Plotnost dereva zadana neverno. Vvedennoe chislo ne yavlyaetsa polozhitelnym.\n");
		return;
	}
	printf("Vvedite plotnost DSP v g/m^3 \n");
	scanf("%lf", &p_dsp);
	if (p_dsp <= 0)
	{
		printf("Plotnost DSP zadana neverno. Vvedennoe chislo ne yavlyaetsa polozhitelnym.\n");
		return;
	}
	printf("Vvedite plotnost DVP v kg/m^3 \n");
	scanf("%lf", &p_dvp);
	if (p_dvp <= 0)
	{
		printf("Plotnost DVP zadana neverno. Vvedennoe chislo ne yavlyaetsa polozhitelnym.\n");
		return;
	}
	t_der = 0.01;
	t_dsp = 0.015;
	t_dvp = 0.005;
	printf("Vvedite vysotu skapha v santimetrah (ot 180 do 220 cm) \n");
	scanf("%lf", &h);
	if (h < 180 || h > 220)
	{
		printf("Vysota zadana neverno. Vvedennoe chislo ne vhodit v predely ot 180 do 220 cm \n");
		return;
	}
	h = h * 0.01;
	printf("Vvedite shirinu skapha v santimetrah (ot 80 do 120 cm) \n ");
	scanf("%lf", &w);
	if (w < 80 || w > 120)
	{
		printf("Shirina zadana neverno. Vvedennoe chislo ne vhodit v predely ot 80 do 120 cm \n");
		return;
	}
	w = w * 0.01;
	printf("Vvedite glubinu skapha v santimetrah (ot 50 do 90 cm) \n");
	scanf("%lf", &d);
	if (d < 50 || d > 90)
	{
		printf("Glubina zadana neverno. Vvedennoe chislo ne vhodit v predely ot 50 do 90 cm \n");
		return;
	}
	d = d * 0.01; //перевод в метры
	m_zst = p_dvp * t_dvp * (h - 2 * t_dsp) * w;
	m_bok = 2 * p_dsp * t_dsp * (h - 2 * t_dsp) * (d - t_dvp);
	m_kr = 2 * p_dsp * w * d * t_dsp;
	m_dv = p_der * h * t_der * w;
	m_p = p_dsp * (h - 2 * t_dsp) / (0.4 + t_dsp) * (w - 2 * t_dsp) * (d - t_dvp);
	M = (m_p + m_kr + m_bok + m_zst + m_dv);
	printf("Massa shkapha ravna (v kg) %lf", M);
}