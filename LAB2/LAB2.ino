//Using stdbool so that I can use the boolean operator
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//Prototype declaration
bool check_sort(float temps[], int n);
void sort(float temps[], int n);
void swap(float *xp, float *yp);
float average(float temps, int n);
void fan_speed(float temps[], int size_arr);

//Pre defined vars
int pin_two = 10;
int pin_three = 11;
int arr[3] = {pin_two, pin_three};
int pins = 2;

void setup() 
{
    pinMode(A0, INPUT);
    for (int x = 0; x < pins; x++)
        pinMode(arr[x], OUTPUT);
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
        float i = (rand() % (80 - 1) + 20.0);
        temps[x] = i; 
    //    m_v = (analogRead(A0)*(5000.0/1024.0));
    //    float c = (m_v-m_v0)/t;
    }
    bool check = check_sort(temps, n);

    if (!check) {
        sort(temps, n);
        for (int i = 0; i < n; i++) 
        {
            Serial.print(i);
            Serial.print(" Temp -> ");
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
    fan_speed(temps, n);
}

void fan_speed(float temps[], int size_arr)
{
    //Calculating PWM signal from 0 -> 255
    //float val = ((255*log10(n))/6);  
    for (int x = 0; x < size_arr; x++)
    {
        float val = ((5.1*pow(temps[x], 2)+0.1)/200);
        int val_percentage = ((val/355)*100);
        Serial.println(val);
        Serial.print("Fan is running at: ");
        Serial.print(val_percentage);
        Serial.println("%");
        analogWrite(pin_two, temps[0]);
        analogWrite(pin_three, temps[x]);
        delay(1000);
    }
}

float average(float temps[], int n)
{
    float holder = 0;
    for (int x = 0; x < n; x++)
        holder += temps[x];

    Serial.println(holder);
    holder = holder/n;
    Serial.println(holder);
    return holder;
}

int check_sort(float temps[], int n) 
{
    if (n == 1 || n == 0) { 
        return true;
    } 
    
    if (temps[n - 1] < temps[n - 2]) {
        return false;
    }
    
    return check_sort(temps, n - 1);
}

void sort(float temps[], int n)
{
    for (int x = 0; x < n; x++)
        for (int i = 0; i < n - x - 1; i++)
            if (temps[i] > temps[i + 1])
                swap(&temps[i], &temps[i + 1]);
}

void swap(float *xp, float *yp)
{ 
    float temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
