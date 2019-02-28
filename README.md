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
                - temp < 18 = 0%
                - 18 < temp < 22 = [20%, 40%]
                - temp > 22 = [40%, 90%]


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

pin 1,2,7 are being used, they are inputs
pin 3,6 are outputs

Source:
    http://www.ti.com/lit/ds/symlink/l293.pdf

## Connecting everything

TMP36 -> A0
L293D -> 1 -> D9
         2 -> D10
         7 -> D11
         3&6 -> Motor


## Calculating the log(average)

[Log plot](https://secretmud.github.com/fan_controll/img/log_plot.png)
