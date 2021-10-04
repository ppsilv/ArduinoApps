/*
 * Version: 202110CPUPWR1210CONNPWRBRD2010
 * -Compilando porém não testado.
 * * butoes.ino
 * * tachometer.ino
 * * teclado.ino
 * * testeEncoder.ino preciso testar esse codigo para pegar subsídios e montar o código para RDO_axis.
 * 
 * 
 * 
 * Connector in output board 
 * 
 * 
 * Connectors to outside box
 * 
 * DB9 conector
 * pin fio
 * 1   laranja     12V relés
 * 2   cinza       run forward
 * 3   branco      sinal liga relés da placa de potencia
 * 4   branco      Potentiomer signal
 * 5   amarelo     run backward
 * 6   preto       gnd
 * 7   preto       gnd placa potencia
 * 8   vermelho    5V potentiometer 
 * 9   vermelho    5V vindo da placa de potencia
 * 
 * DB9 pins 
 * Pin 4,8 and 6 they are in a potentiometer's connector named POT  
 * Pin 1 and 6 they are in a power's input connector named Power IN
 * 
 * The other pins are going to J500 connector
 * 
 * 
 * 
 * Connectors to connect output board to motherboard
 * 
 * Axis Y connector
 * 
 * 1 - clk yellow cable
 * 2 - data white cable
 * 3 - GND black cable
 * 4 - GND black cable
 * 5 - 3,3V gray cable
 * 
 * Axis X connector
 * 
 * 1 - 5V red cable
 * 2 - GND black cable
 * 3 - Signal One green cable
 * 4 - Signal Two white cable
 * 5 - No connection
 * 
 * J500 to J105
 * 1 - CPU RPM sensor purple cable
 * 2 - Run forward gray cable
 * 3 - GND black cable
 * 4 - Relay ON white cable
 * 5 - Run backward yellow cable
 * 
 * 
 * 
 * Connectors from motherboard
 * 
 * J100 connects to lcdBoard
 * 1 - 5V red cable
 * 2 - TX rs232 orange cable
 * 3 - No connect
 * 4 - RX rs232 yellow cable
 * 5 - GND black cable
 * 
 * J106 connects to buttons and leds
 * 1 - Led reverse button ON brown cable
 * 2 - Led stop button ON blue cable
 * 3 - Led start button ON green cable
 * 4 - Reverse button brown cable
 * 5 - Stop button blue cable
 * 6 - Start button green cable
 * 
 * 
 */
 
