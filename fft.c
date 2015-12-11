#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


typedef struct{
	double real, imag;
} complex;


double entrada8[] = {
	1.000000000000000,
  -0.707106781186547,
  -0.000000000000000,
   0.707106781186548,
  -1.000000000000000,
   0.707106781186547,
   0.000000000000001,
  -0.707106781186547
};
double entrada16[] = {
	1.000000000000000,
   0.382683432365090,
  -0.707106781186547,
  -0.923879532511287,
  -0.000000000000000,
   0.923879532511287,
   0.707106781186548,
  -0.382683432365090,
  -1.000000000000000,
  -0.382683432365091,
   0.707106781186547,
   0.923879532511287,
   0.000000000000001,
  -0.923879532511286,
  -0.707106781186547,
   0.382683432365090
  };
double entrada64[] = {
	1.000000000000000,
   0.956940335732209,
   0.831469612302545,
   0.634393284163645,
   0.382683432365090,
   0.098017140329561,
  -0.195090322016128,
  -0.471396736825998,
  -0.707106781186547,
  -0.881921264348355,
  -0.980785280403230,
  -0.995184726672197,
  -0.923879532511287,
  -0.773010453362737,
  -0.555570233019602,
  -0.290284677254462,
  -0.000000000000000,
   0.290284677254462,
   0.555570233019602,
   0.773010453362737,
   0.923879532511287,
   0.995184726672197,
   0.980785280403230,
   0.881921264348355,
   0.707106781186548,
   0.471396736825998,
   0.195090322016129,
  -0.098017140329560,
  -0.382683432365090,
  -0.634393284163645,
  -0.831469612302545,
  -0.956940335732208,
  -1.000000000000000,
  -0.956940335732209,
  -0.831469612302546,
  -0.634393284163645,
  -0.382683432365091,
  -0.098017140329561,
   0.195090322016127,
   0.471396736825997,
   0.707106781186547,
   0.881921264348355,
   0.980785280403230,
   0.995184726672197,
   0.923879532511287,
   0.773010453362738,
   0.555570233019603,
   0.290284677254464,
   0.000000000000001,
  -0.290284677254463,
  -0.555570233019602,
  -0.773010453362737,
  -0.923879532511286,
  -0.995184726672197,
  -0.980785280403231,
  -0.881921264348356,
  -0.707106781186547,
  -0.471396736825998,
  -0.195090322016130,
   0.098017140329561,
   0.382683432365090,
   0.634393284163644,
   0.831469612302544,
   0.956940335732209
  };

complex mult(complex z1, complex z2);
complex soma(complex z1, complex z2);
void reverteBit(complex * x, int N);
void mostraResultado(complex * x1, int N);
void fft(complex * x, int N);
complex W(int n, int kk);
complex * le(int * N);

void main(){
	int MAX = 1, ka, e, n, i;
	clock_t end,start;
		
	/* 8 ENTRADAS *
	complex * x_ent = malloc(8 * sizeof(complex));
	for(ka=0;ka<8;ka++) {
		x_ent[ka].real = entrada8[ka];
		x_ent[ka].imag = 0;
	}
	start = clock();
	reverteBit(x_ent, 8);
	fft(x_ent, 8);
	//dft(x_ent);
	end = clock();
	//mostraResultado(x_ent, 8);
	printf(" 8 ENTRADAS FFT: \n");
	printf("Tempo total do calculo: %4.4f ms\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
	printf("Aproximadamente: %4.4f segundos\n",(double)(end-start)/(double)(CLOCKS_PER_SEC));
	
	/* 16 ENTRADAS *
	complex * x_ent = malloc(16 * sizeof(complex));
	for(ka=0;ka<16;ka++) {
		x_ent[ka].real = entrada16[ka];
		x_ent[ka].imag = 0;
	}
	start = clock();
	reverteBit(x_ent, 16);
	fft(x_ent, 16);
	//dft(x_ent);
	end = clock();
	mostraResultado(x_ent, 16);
	printf(" 16 ENTRADAS FFT: \n");
	printf("Tempo total do calculo: %4.4f ms\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
	printf("Aproximadamente: %4.4f segundos\n",(double)(end-start)/(double)(CLOCKS_PER_SEC));
	
	/* 64 ENTRADAS *
	complex * x_ent = malloc(64 * sizeof(complex));
	for(ka=0;ka<64;ka++) {
		x_ent[ka].real = entrada64[ka];
		x_ent[ka].imag = 0;
	}
	start = clock();
	reverteBit(x_ent, 64);
	fft(x_ent, 64);
	//dft(x_ent);
	end = clock();
	//mostraResultado(x_ent, 64);
	printf(" 64 ENTRADAS FFT: \n");
	printf("Tempo total do calculo: %4.4f ms\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
	printf("Aproximadamente: %4.4f segundos\n",(double)(end-start)/(double)(CLOCKS_PER_SEC));
	*/
	
	complex * x_ent = le(&MAX);
	reverteBit(x_ent, MAX);
	start = clock();
	
	fft(x_ent, MAX);
	end = clock();
	mostraResultado(x_ent, MAX);
	printf(" ENTRADA ARQUIVO VOZ.DAT FFT: \n");
	printf("Tempo total do calculo: %4.4f ms\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
	printf("Aproximadamente: %4.4f segundos\n",(double)(end-start)/(double)(CLOCKS_PER_SEC));
	
}

complex * le(int * N){
	FILE *fp;
	complex * x1;
	int t = 0, flag = 0;
	double x, resultado;
	char arquivo[15] = "voz.dat";
	fp = fopen(arquivo,"r");
	// Verifica se a abertura ocorreu com sucesso
	if(fp==NULL){
		printf("Impossivel abrir arquivo %s",arquivo);
	}else{
		printf("\n Arquivo %s aberto com sucesso \n",arquivo);
		while (!feof(fp)){
			resultado = fscanf(fp, "%lf", &x);
			if(flag != 0) {
				x1[t].real = x;
				x1[t].imag = 0.0;
				t++;
			}else{
				*N = (int)x;
				x1 = malloc(x * sizeof(complex));
				flag = 1;
			}
		};
		fclose(fp);
		printf("\n");
	}
	printf("\n DADOS CARREGADO \n");
	return x1;
}

void reverteBit(complex * x, int N){
	int ka, c, temp1, temp2, temp3 = 0;
	temp2 = N/2; // COMECA NA METADE
	for(c=1;c<(N-1);c++) {
		// COMECA PELA METADE, PULANDO O PRIMEIRO E ULTIMO
		temp1 = temp2;
		while(temp3>=temp1){
			temp3 = temp3 - temp1;
			temp1 = temp1/2; 
		}
		temp3 = temp3 + temp1;
		if(c<temp3){
			complex c_temp = x[c];
			x[c] = x[temp3];
			x[temp3] = c_temp;
		}
	}
	/*printf("\n REVERTIDO \n\n");
	for(ka=0;ka<N;ka++) {
		printf("REAL X[%d]: %lf - IMG: %lf -- \n", ka, x_ent[ka].real, x_ent[ka].imag);
	}*/
}

void fft(complex * x, int N){
	int estagios = log2(N), ka, indiceWD = 2, c, temp1, temp2;
	double w, s, t1, t2, temp;
	complex c_temp;
	complex * Xf = malloc(N * sizeof(complex));
	int ant = 0, a, b, d;
	for(c = 1; c <= estagios; c++) {
		temp2 = N/c;
		
		//printf("\nESTAGIO: %d ", c);
		for(temp1 = 0; temp1 < indiceWD; temp1++) {
			//printf("\nUP: %d - DOWN: %d  === ", temp1, indiceWD);
			for(temp2=0; temp2 < (N/indiceWD); temp2++){
				a = temp1 + (temp2*indiceWD);
				d = indiceWD/2;
				//Xf[temp1 + (temp2*indiceWD)] = soma(x[temp1 + (temp2*indiceWD)], mult(x[temp1 + (temp2*indiceWD) + ((indiceWD/2) * (int)pow(-1, indiceWD))], W(temp1, indiceWD)));
				if(temp1 >= d){
					b = a - d;
					//printf("P2X[%d]--%d=%d--  ", a, a, b, temp1, indiceWD);
					Xf[a] = soma(x[b], mult(x[a], W(temp1, indiceWD)));
				}else{
					b = a + d;
					//printf("P1X[%d]--%d=%d--  ", a, a, b, temp1, indiceWD);
					Xf[a] = soma(x[a], mult(x[b], W(temp1, indiceWD)));
				}
			}
		}
		//ATUALIZA AS ENTRADAS P/ O PROXIMO ESTAGIO
		for(ka=0;ka<N;ka++) {
			x[ka] = Xf[ka];
		}
		indiceWD = indiceWD * 2;
	}
	printf("\n FFT \n");
}

void mostraResultado(complex * x1, int N){
	int ka;
	for(ka=0;ka<N;ka++) {
		printf("REAL X[%d]: %lf - IMG: %lf -- \n", ka, x1[ka].real, x1[ka].imag);
	}
}

complex W(int n, int kk){
	complex z;
	double angulo = n*2*M_PI/kk;
	z.real = cos(angulo);
   z.imag = -sin(angulo);
	//printf("ELEVADO %d %d REAL: %lf - IMG: %lf -- \n", n, kk, z.real, z.imag);
	return z;
}

complex soma(complex z1, complex z2){
	complex z;
	z.real = (z1.real + z2.real);
	z.imag = (z1.imag + z2.imag);
	return z;
}

complex mult(complex z1, complex z2){
	complex z;
	z.real = ((z1.real*z2.real) - (z1.imag*z2.imag));
	z.imag = ((z1.real*z2.imag) + (z2.real*z1.imag));
	return z;
}
