#include <stdio.h>
#include <string.h>

int main(void){
    
}

bool esprimo(int n){
    int cant=1;
    for(int i=2;i<=(n/2);i++){
        if (n%i==0){
        cant++;
        }
        if (cant>1){
            return false;
        }
    }
return true;
}

int gcd(int a, int b) { //Máximo Común Divisor (GCD):
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {  //Mínimo Común Múltiplo (LCM):
    return (a / gcd(a, b)) * b;
}

void sieve(int n, bool isPrime[]) { //numeros primos hasta n
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}

void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
}
bool isPalindrome(char str[]) {
    int l = 0, h = strlen(str) - 1;
    while (h > l) {
        if (str[l++] != str[h--]) {
            return false;
        }
    }
    return true;
}
bool twoSum(int arr[], int n, int target) { //true si la suma de 2 numeros devuelve target
    sort(arr, arr + n);
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}
int sumatoria(int x,int y){ //sumatoria de x a y
return (y*(y+1)/2 -(x-1)*(x)/2);
}

int combination(int n, int k) {
    if (k == 0 || k == n) return 1;
    return combination(n - 1, k - 1) + combination(n - 1, k);
}


void permute(string a, int l, int r) {
    if (l == r)
        cout << a << endl;
    else {
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]);
            permute(a, l + 1, r);
            swap(a[l], a[i]);
        }
    }
}



/*Combinaciones

cpp

int combination(int n, int k)

    n: El total de elementos.
    k: El número de elementos en cada combinación.

Calcula el número de formas de elegir k elementos de un conjunto de n elementos. Útil en problemas de combinatoria y probabilidad.
Permutaciones

cpp

void permute(string a, int l, int r)

    a: La cadena de caracteres que queremos permutar.
    l: El índice de inicio de la subcadena a permutar.
    r: El índice final de la subcadena a permutar.

Esta función genera todas las permutaciones de la cadena a. Es útil en problemas de generación de posibles combinaciones y búsqueda exhaustiva.
*/