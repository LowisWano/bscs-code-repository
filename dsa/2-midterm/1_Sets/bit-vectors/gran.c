#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int *elem; // present - 1, absent - 0
    int count;
    int max;
}Set;

Set createSet(int max);
void initSet(Set *s, int max);

bool addElement(Set *s, int item);
bool removeElement(Set *s, int item);
void displaySet(Set s);
bool isElement(Set s, int item);
bool isSubset(Set a, Set b);

Set unionSet(Set a, Set b);
Set intersectionSet(Set a, Set b);
Set differenceSet(Set a, Set b);
Set symmetricDifferenceSet(Set a, Set b);

int main(void){
    Set s;
    Set t;
    Set new;
    initSet(&s, 5);
    initSet(&t, 10);
    
    addElement(&s, 1);
    addElement(&s, 2);

    addElement(&t, 1);
    printf("is subset: %d\n", isSubset(s, t));
    displaySet(s);
    displaySet(t);
    new = unionSet(s,t);
    displaySet(new);
}

Set unionSet(Set a, Set b){
    Set biggerSet = (a.max > b.max)?a:b;
    Set smallerSet = (a.max > b.max)?b:a;
    Set new = createSet(biggerSet.max);
    int i;

    for(i=0;i<smallerSet.max;i++){
        new.elem[i] = a.elem[i] | b.elem[i];
    }

    for(;biggerSet.max > smallerSet.max && i < biggerSet.max; i++){
        new.elem[i] = biggerSet.elem[i];
    }
    return new;
}

// figure out how to handle different max
bool isSubset(Set a, Set b){
    Set mainSet = a;
    int i;
    for(i=0;i<mainSet.max;i++){
        if(b.elem[i] == 1 && a.elem[i] == 0){
            break;
        }
    }
    return i == a.max ? true:false;
}

bool isElement(Set s, int item){
    return (s.elem[item] == 1) ? 1:0;
}

void displaySet(Set s){
    int i;
    for(i=0;i<s.max;i++){
        printf("%d ",s.elem[i]);
    }
    printf("\n");
}

bool removeElement(Set *s, int item){
    if(item < s->max &&  s->elem[item] != 0){
        s->elem[item] = 0;
        s->elem--;
        return true;
    }
    return false;
}

bool addElement(Set *s, int item){
    if(item < s->max &&  s->elem[item] == 0){
        s->elem[item] = 1;
        s->count++;
        return true;
    }
    return false;
}

Set createSet(int max){
    Set new;
    new.elem = malloc(sizeof(int)*max);
    new.max = max;
    new.count = 0;
    return new;
}

void initSet(Set *s, int max){
    s->elem = malloc(sizeof(int)*max);
    s->max = max;
    s->count = 0;
}