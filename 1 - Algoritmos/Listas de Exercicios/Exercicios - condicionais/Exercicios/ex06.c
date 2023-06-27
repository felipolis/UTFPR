#include <stdio.h>

int main() {

int a, b, c;
float media;

printf("Digite a idade do primeiro aluno: ");
scanf("%d", &a);

printf("Digite a idade do segundo aluno: ");
scanf("%d", &b);

printf("Digite a idade do terceiro aluno: ");
scanf("%d", &c);

media = (a+b+c)/3;

if(media<=25){
    printf("Turma Jovem");
} else if(media>25 && media<=40){
    printf("Turma Adulta");
} else{
    printf("Turma Avançada");
}

return 0;

}
