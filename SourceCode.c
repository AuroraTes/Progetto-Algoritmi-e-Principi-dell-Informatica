#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define INF 4294967296
#define GRAFI 2000000


struct infografo{
	int id_grafo;
	int costo;
	};
	
typedef struct infografo infografo;



int conversione(char *str){
	int x=0;
	
	while(*str){
		x=(x<<3) + (x<<1) + (*str) - '0';
		str++;
	}
	return x;
}
	



int ordinacosti (const void *a,const void *b){

	infografo *costo1 = (infografo *)a;
	infografo *id_grafo1 = (infografo *)b;
	return ( costo1->costo - id_grafo1->costo);
}
		



int Dijkstra (int **mat,int d){
	long int dist[d],coda[d];
	int i=0,j,costocum=0,sum,k;
	long int min=INF;
	
	dist[0]=0;
	coda[0]=1;
	
	for(i=1;i<d;i++){
		dist[i]=INF;
		coda[i]=0;
		
	}
	
	i=0;
	for(k=0;k<d;k++){
		for(j=0;j<d;j++){
			if(mat[i][j]!= 0 && i!=j){
				sum=dist[i]+mat[i][j];
				if(sum<dist[j]){
					dist[j]=sum;
					coda[j]=1;
				}
			}
		}
	
		
		coda[i]=0;
	
		for(j=0;j<d;j++){
			if(coda[j]==1)
				if(dist[j]<min){
					min=dist[j];
					i=j;
				}
		}
		
	min=INF;
	
	}
	
	for(i=1;i<d;i++){
		if(dist[i]!=INF)
			costocum=costocum+dist[i];
	}
	return costocum;
	
}


int AggiungiGrafo(int **mat, int d){
	int i,j,g=0,var=0;
	int len=0,test,col=0,righe=0;
	int costocum;
	char *a,*b;
	
	
	for(j=0;j<d;j++){
		a=calloc(d*2-1,sizeof(long int));
		b=calloc(22,sizeof(char));
		
		if(a==NULL)
			printf("\nAllocazione fallita\n");
		
		else{
			if(scanf("%s", a)!=EOF)
				len=strlen(a);
			
			for(i=0;i<len+1;i++){
				test=a[i];
				
				if(test>47&&test<58){
					b[g]=a[i];
					g++;
				}
				else{
					var=conversione(b);
					g=0;
					memset(b,0,strlen(b));
					
					if(test==44){
						mat[righe][col]=var;
					col++;
					}
					
					else{
						mat[righe][col]=var;
						free(a);
						free(b);
						col=0;
						righe++;
					}
				}
			}
		}
	}
	

	
	costocum=Dijkstra(mat,d);
	

	
	
	
	return costocum;
}

void TopK(infografo vett_costi[], int dim, int k){
	int i;
	
	if(dim==0){
		printf("\n");
		return;
	}
	
	
	
	qsort(vett_costi, dim, sizeof(infografo), ordinacosti);
	
	
	if(dim<k){
		for(i=0;i<dim;i++){
			if(i==0)
				printf("%d ",vett_costi[i].id_grafo);
			else{
				if(vett_costi[i].costo!= vett_costi[i-1].costo){
				printf("%d ",vett_costi[i].id_grafo);	
				}
					
			}
		}
		
		printf("\n");
	}
	
	
	else{
		for(i=0;i<k;i++){
			if(i==0)
				printf("%d ",vett_costi[i].id_grafo);
			else{
				if(vett_costi[i].costo!=vett_costi[i-1].costo){
				printf("%d ",vett_costi[i].id_grafo);	
				}
					
			}
		}
		
		printf("\n");
	}
	
}

	
int main(){
	int d=0,k=0;
	int len,id_grafo=0,costomin;
	infografo *vett_costi=NULL;
	char comando[14];
	int **mat=NULL,i;
	
	if(scanf("%d ",&d)<0)
		return 0;
	if(scanf("%d",&k)<0)
		return 0;
		
	mat=(int**)calloc(d,sizeof(int*));
	
	for(i=0;i<d;i++){
		mat[i]=calloc(d,sizeof(int));
	}
	
	vett_costi=calloc(GRAFI,sizeof(infografo)); 
	
	
	do{	
		if(scanf("%s",comando)!=EOF)
			len=strlen(comando);
			
		else{
			free(vett_costi);
			for(i=0;i<d;i++){
				free(mat[i]);
			}
			
			free(mat);
			return 0;
		}
		
	
		if(len==13){
			costomin = AggiungiGrafo(mat,d);
			vett_costi[id_grafo].costo=costomin;
			vett_costi[id_grafo].id_grafo=id_grafo;
			id_grafo++;
				
		}			

			
		if(len==4){
			TopK(vett_costi,id_grafo,k);
			
		}
	
		
	}while(1);
	
	return 0;
}


























		
	
