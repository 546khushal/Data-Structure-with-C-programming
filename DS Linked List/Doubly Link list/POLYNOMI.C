/*
WAP to create two doubly linked lists and perform polynomial addition
Name: Khushal
Date: 05/02/2025
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct DoublyLinkedList {
    int coff, exp;
    struct DoublyLinkedList *next;
    struct DoublyLinkedList *prev;
} Poly;

void Append(Poly **p, int coff, int ex) {
    Poly *tmp, *r;
    tmp = *p;
    r = (Poly *)malloc(sizeof(Poly));
    r->coff = coff;
    r->exp = ex;
    r->next = NULL;
    r->prev = NULL;

    if (*p == NULL || (*p)->exp < ex) {
        r->next = *p;
        if (*p != NULL)
            (*p)->prev = r;
        *p = r;
    } else {
        while (tmp->next != NULL && tmp->next->exp >= ex) {
            tmp = tmp->next;
        }
        r->next = tmp->next;
        if (tmp->next != NULL)
            tmp->next->prev = r;
        tmp->next = r;
        r->prev = tmp;
    }
}

void Add(Poly *p, Poly *q, Poly **st) {
    if (p == NULL && q == NULL) {
        printf("Linked List is Empty\n");
        return;
    }
    while (p != NULL && q != NULL) {
        if (p->exp > q->exp) {
            Append(st, p->coff, p->exp);
            p = p->next;
        } else if (p->exp < q->exp) {
            Append(st, q->coff, q->exp);
            q = q->next;
        } else {
            Append(st, p->coff + q->coff, p->exp);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL) {
        Append(st, p->coff, p->exp);
        p = p->next;
    }
    while (q != NULL) {
        Append(st, q->coff, q->exp);
        q = q->next;
    }
}

void Display(Poly *p) {
    if (p == NULL) {
        printf("The List is Empty!\n");
        return;
    }
    while (p != NULL) {
        if (p->exp == 0)
            printf("%d", p->coff);
        else
            printf("%dx^%d + ", p->coff, p->exp);
        p = p->next;
    }
    printf(" = 0\n");
}

void Menu() {
    printf("\n1. Append First Polynomial");
    printf("\n2. Display First Polynomial");
    printf("\n3. Append Second Polynomial");
    printf("\n4. Display Second Polynomial");
    printf("\n5. Add First & Second Polynomial");
    printf("\n6. Exit");
    printf("\n\nEnter Your Choice: ");
}

void main() {
    int ch, cof, ex;
    Poly *start1 = NULL;
    Poly *start2 = NULL;
    Poly *result = NULL;

    do {
        clrscr();
        Menu();
        scanf("%d", &ch);
        switch (ch) {
            case 1: // First polynomial
                printf("\nEnter Coefficient (p1): ");
                scanf("%d", &cof);
                printf("\nEnter Exponent (p1): ");
                scanf("%d", &ex);
                Append(&start1, cof, ex);
                break;
            case 2: // Display first polynomial
                Display(start1);
                break;
            case 3: // Second polynomial
                printf("\nEnter Coefficient (p2): ");
                scanf("%d", &cof);
                printf("\nEnter Exponent (p2): ");
                scanf("%d", &ex);
                Append(&start2, cof, ex);
                break;
            case 4: // Display second polynomial
                Display(start2);
                break;
            case 5: // Add both polynomials
                Display(start1);
                Display(start2);
                printf("______________________________________________________________________________\n");
                Add(start1, start2, &result);
                Display(result);
                printf("______________________________________________________________________________\n");
                break;
            case 6:
                clrscr();
                gotoxy(35, 12);
                printf("Thank you!");
                break;
            default:
                printf("Invalid Choice! Please try Again\n");
        }
        getch();
    } while (ch != 6);
}
