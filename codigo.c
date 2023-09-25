#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

// Calculo

double areacalcular(Point vertices[], int numVertices) {
    double resultadovert = 0.0;

    for (int i = 0; i < numVertices - 1; i++) {
        resultadovert += (vertices[i].x * vertices[i + 1].y - vertices[i + 1].x * vertices[i].y);
    }

    resultadovert += (vertices[numVertices - 1].x * vertices[0].y - vertices[0].x * vertices[numVertices - 1].y);

    return fabs(resultadovert) / 2.0; 
}

int main() {
    FILE *arquivoentradas, *arquivosaida;
    int vertices1;

    /*

    3  
    1.0 2.0  
    3.0 8.0  
    5.0 1.0  

    Nesta ordem */

    arquivoentradas = fopen("vertices.txt", "r"); 


// Condições 

    if (arquivoentradas == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }
    
    fscanf(arquivoentradas, "%d", &vertices1);
    
    if (vertices1 < 3) {
        printf("O polígono deve ter no minimo 3 vértices.\n");
        fclose(arquivoentradas);
        return 1;
    }
    
    Point *points = (Point *)malloc(vertices1 * sizeof(Point));
    
    if (points == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivoentradas);
        return 1;
    }
    
    for (int i = 0; i < vertices1; i++) {
        fscanf(arquivoentradas, "%lf %lf", &points[i].x, &points[i].y);
    }
    
    fclose(arquivoentradas);
    
    double areavert = areacalcular(points, vertices1);
    
    printf("A area do poligono foi: %.2lf\n", areavert);
    
    /* Apenas para teste */

    arquivosaida = fopen("area.txt", "w");
    
    if (arquivosaida == NULL) {
        printf("Erro ao criar o arquivo de saída com o resultado.\n");
        free(points);
        return 1;
    }
    
    fprintf(arquivosaida, "A area do poligono foi: %.2lf\n", areavert);
    
    fclose(arquivosaida);
    
    printf("Arquivo de saida criado com sucesso!");

    free(points);
    
    return 0;
}
