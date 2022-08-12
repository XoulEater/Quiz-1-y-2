# Quiz-1-y-2

Para la estructura del tren utilice una lista de strucks llamada vagones
los cuales contienen un char con el caracter ASCII representativo del
nombre y una matriz que representa los asientos del vagon, la matriz
esta compuesta por 1 y 0, los 1 indican que el espacio se encuentra
ocupado mientras que los 0 indican que el asiento está disponible como
se muestra a continuacion:

    vagon train[] = {
        {0x41,            //Vagon A
        //1 2 3 4 5 6    
        {{1,0,0,0,0,0},   //Fila 1
         {0,1,0,0,0,0},   //Fila 2
         {0,0,1,0,0,0},   //Fila 3
         {0,0,0,1,0,0},   //Fila 4
         {0,0,0,0,1,0},   //Fila 5
         {0,0,0,0,0,1}}}, //Fila 6
         
        {0x42,            Vagon B
        //1 2 3 4 5 6
        {{0,0,0,0,0,1},   //Fila 1
         {0,0,0,0,1,0},   //Fila 2
         {0,0,0,1,0,0},   //Fila 3
         {0,0,1,0,0,0},   //Fila 4
         {0,1,0,0,0,0},   //Fila 5
         {1,0,0,0,0,0}}}, //Fila 6
         
Las listas generadas almacenan los datos del asiento en forma de string 
para una mayor compresion, se utiliza el siguiente formato:

Nombre del vagon, Numero de la Fila, /, Numero del asiento

Ejemplo: A1/2
