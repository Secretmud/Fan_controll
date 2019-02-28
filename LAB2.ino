//Using stdbool so that I can use the boolean operator
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//Prototype declaration
int check_sort(float temps[], int n);
void sort(float temps[], int n);
void swap(float *xp, float *yp);
float average(float temps, int n);
void fan_speed(float average);


void setup() 
{
    pinMode(A0, INPUT);
    Serial.begin(9600);
}

void loop() 
{
    float m_v;
    float m_v0 = 500.0;
    float t = 10.0;
    int n = 20; //array length
    float temps[n];
    for (int x = 0; x < n; x++) 
    {
        float i = rand() % 60;
        temps[x] = i; 
    /*    m_v = (analogRead(A0)*(5000.0/1024.0));
        if (m_v == 500.0) {
            temps[x] = 0; 
        
        } else {
            float c = (m_v-m_v0)/t;
            temps[x] = c; 
        
        } 
    */
    }
    bool check = check_sort(temps, n);

    if (!check) {
        sort(temps, n);
        for (int i = 0; i < n; i++) 
        {
            Serial.print("Temp -> ");
            Serial.println(temps[i]);
        }
    } 
    float average_temp = average(temps, n);
    Serial.println("The following temps are as following: Min, Max, Average:");
    Serial.print("Min -> ");
    Serial.println(temps[0]);
    Serial.print("Max -> ");
    Serial.println(temps[n - 1]);
    Serial.print("Average -> ");
    Serial.println(average_temp);
    fan_speed(average_temp);
}

void fan_speed(float n)
{
    //The logarithm to calculate PWM signal from 0 -> 255
    float val = ((255*log10(n))/3);  
    int val_percentage = ((val/255)*100);
    if (n < 18) {
        Serial.println("Fan not running"); 
    } else if ( n > 18 ) {
        Serial.print("Fan is running at: ");
        Serial.print(val_percentage);
        Serial.println("%");
    }
    delay(15000);
}

float average(float temps[], int n)
{
    float holder = 0;
    for (int x = 0; x < n; x++)
    {
        holder += temps[x];

    }
    Serial.println(holder);
    holder = holder/n;
    Serial.println(holder);
    return holder;
}

int check_sort(float temps[], int n) //n is the array length 
{
    if (n == 1 || n == 0) {
        return true;
    } 
    
    if (temps[n - 1] < temps[n - 2]) {
        return false;
    }
    
    return check_sort(temps, n - 1);
}

void sort(float temps[], int n)//Bubblesort
{
    float holder;
    for (int x = 0; x < n; x++)
        for (int i = 0; i < n - x - 1; i++)
            if (temps[i] > temps[i + 1])
                swap(&temps[i], &temps[i + 1]);
}

void swap(float *xp, float *yp)//Swapping the values in temps
{ 
    float temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
