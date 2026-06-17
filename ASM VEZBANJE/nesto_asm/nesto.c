//#include <stdio.h>
//
//int main() {
//	short matrica[10][10];
//	short niz[100];
//
//	int M, N;
//
//	int i, j;
//	int temp;
//
//	printf("Unesi M i N : ");
//	scanf("%d %d", &M, &N);
//
//	printf("Unesi elemente matrice: ");
//	for (i = 0; i < M; i++) {
//		for (j = 0; j < N; j++) {
//			scanf("%hd", &matrica[i][j]);
//		}
//	}
//	__asm {
//		lea esi, matrica // adresa matrice
//		lea edi,niz // adresa niza
//		xor ebx,ebx // j = 0
//	Spoljna_Petlja:
//		cmp ebx,N //j >= N ?
//		jge Kraj // ako da kraj
//		xor ecx,ecx // i = 0
//	Unutrasnja_Petlja:
//		cmp ecx,M // i >= M ?
//		jge Sledeca_Kolona// ako da jump
//		mov eax,ecx 
//		mov edx,20 
//		imul edx // edx(gde je i) * 20
//		mov edx,ebx
//		shl edx,1 // j * 2
//		add eax, edx 
//		mov dx,[esi + eax] // base + (i * sirina reda ) + (j * 2)
//		mov [edi],dx // trenutni element
//		add edi,2 // sledeci element
//		inc ecx // i ++
//		jmp Unutrasnja_Petlja
//	Sledeca_Kolona:
//		inc ebx
//		jmp Spoljna_Petlja
//	Kraj:
//		mov word ptr[edi], 0
//		mov word ptr[edi + 2], 0
//		mov word ptr[edi + 4], 0
//	}
//
//		
//
//
//	i = 0;
//	while (1) {
//		
//		if (niz[i] == 0 && niz[i + 1] == 0 && niz[i + 2] == 0) {
//			break;
//		}
//		printf("%d ", niz[i]);
//		i++;
//	}
//
//}
//.data
//S dw 25
//N dd 0
//P dd 0
//M dd 1
//i dd 1
//
//.code
//xor eax,eax
//mov ax,S
//shr ax,3
//mov ebx,eax // s/8
//mov esi,M
//mov ecx,i
//petlja:
//mov edi,esi // s/8
//add esi,ebx // Mi-1 + s/8
//movzx edx,word ptr[S]
//cmp esi,edx
//ja kraj
//
//mov eax,edi
//mov edx,5
//mul edx
//mov N,eax
//
//mov eax,ecx
//mul ecx
//sub N,eax
//
//mov eax,esi
//add eax,N
//inc eax
//mov P,eax
//inc ecx
//mov i,ecx
//jmp petlja
//kraj:
//end

//.data
//N   dd 10; 
//i   dd 5; 
//SUM dq 0
//.code
//mov ecx,i
//mov esi,N
//
//petlja:
//cmp ecx,esi // i>=N ?
//jge kraj // ako da kraj
//
//mov eax,esi // eax = n
//mov edx,ecx // edx = i
//add eax,edx // n+i
//dec edx // i-1
//idiv edx // n+1/i-1
//.data
//N   dd 10
//i   dd 5
//SUM dq 0
//
//.code
//start :
//mov ecx, i; ecx = i(brojac)
//mov esi, N; esi = N(granica)
//petlja:
//cmp ecx, esi; Poredi i sa N
//jg kraj; 
//mov ebx, ecx; ebx = i
//dec ebx; ebx = i - 1 (Sada je delilac u EBX, siguran je)
//mov eax, esi; eax = n
//add eax, ecx; eax = n + i
//cdq
//idiv ebx
//mov edi,eax // prvi /
//mov eax,esi
//sub eax,ecx
//imul eax
//add eax,edi
//adc edx,0
//add dword ptr[SUM],eax
//adc dword ptr[SUM+4],edx
//inc ecx
//mov i,ecx
//jmp petlja

//.386
//.model flat,c
//.code
//public JeParan
//JeParan proc
//mov eax,[esp+4]
//test eax,1
//jz jeste_paran
//mov eax,0
//ret
//jeste_paran:
//mov eax,1
//ret
//JeParan endp
//
//#include <stdio.h>
//extern int JeParan(int broj);
//
//void main() {
//
//    short MAT[4][4] = {
//        {1, 2, 3, 4},
//        {5, 6, 7, 8},
//        {9, 10, 11, 12},
//        {13, 14, 15, 16}
//    };
//    int M = 4;
//    int brojac = 0;
//    for (int i = 0; i < M; i++) {
//        for (int j = 0; j < M; j++) {
//            if (JeParan(MAT[i][j] == 1)) {
//                brojac++;
//            }
//        }
//    }
//    printf("Parnih: %d", brojac);
//}


//.386
//.model flat
//.data
//niz1 dw 1,2,3,4,5,6
//N dw 6
//niz2 dw 6 dup(?)
//.code
//lea esi,niz1
//lea edi,niz2
//mov ecx,N
//call Prebaci
//
//Prebaci proc
//mov ax,word ptr [esi]
//test ax,ax
//jns preskoci
//mov [edi],ax
//add edi,2
//preskoci:
//add esi,2
//dec ecx
//jnz petlja
//ret
//Prebaci endp

.386
.model flat, stdcall
.data
MAT      dw - 1, 2, 3, -4, 5, -6, 7, 8, -9, 10
M        dw 2
N        dw 5
NOVINIZ  dw 11 dup(?)

.code
mov ax,M
mul N
mov cx,ax // 10(brojac za petlju)
lea esi,MAT
lea edi,NOVINIZ
petlja:
mov ax,[esi]
test ax,ax
jns dalje
mov [edi],ax
add edi,2
dalje:
add esi,2
dec cx
jnz petlja
mov word ptr[edi],1
end

