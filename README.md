# LAB2

## Task

    - Measure the temp 20 times
        - Put them in an array
        - Sort the from min -> max
    - Print the following:
        - temps[min]
        - temps[max]
        - temps[average]
    - Simulate a fan using a DC-motor
        - Make the fan spin acording to the temp average
            - Use the following interval
                - [0C, 100C]


## Circuit info

### Components

    - Arduino uno
    - TMP36
    - DC-motor
    - L293D

### TMP36

The the temperature sensor gives roughly 10mv / C. 
We know that 750mv @ 25C so 500mv @ 0C

So we can asume that the following equation will be giving us the correct temp:

    (m_v - m_v0)/t=C


Source:
    https://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf

### L293D
```
  ____
-|1 16|-
-|2 15|-
-|3 14|-
-|4 13|-
-|5 12|-
-|6 11|-
-|7 10|-
-|8__9|-

```  


    - Input pin(s):
        - 1
        - 2
        - 7
    - Output pin(s): 
        - 3
        - 6

Source:
    http://www.ti.com/lit/ds/symlink/l293.pdf

## Connecting everything

    - TMP36 -> A0
    - L293D -> 1 -> D9
        - 2 -> D10
        - 7 -> D11
        - 3 -> Motor
        - 6 -> Motor

