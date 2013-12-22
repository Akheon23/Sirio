using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ErrorANN
{
    class Program
    {

   
        static void Main(string[] args)
        {


            //Variables
            double[,] Input = new double[300, 608];//Matriz donde va las entrada de la red
            double[,] Output = new double[300,1];//Matriz donde va la salida esperada de la red
            double[,] OutputNN = new double[300, 1];//Matriz donde van numeros
            double[,] weightsInput = new double[50, 608];//Matriz donde van pesos de entrada
            double[,] weightsOutput = new double[1, 50];//Matriz donde van los pesos de salida
            double[,] biasHidden = new double[1, 50];//Matriz donde van numeros
            double[,] maximos = new double[1, 608];//Matriz donde van maximos
            double[,] minimos = new double[1, 608];//Matriz donde van minimos
            double biasOut=(-0.081493651);
            List<double> hidden = new List<double>(new double[51] ); //estado interno neuronas en la capa oculta
            List<double> output = new List<double>(new double[1]); //estado interno neuronas en la capa de salida
            int examples = 300;//Numero de datos para probar
            int hiddenNeurons = 50;//numeo de neuronas en la capa oculta
            int outputNeurons = 1;//numero de neuronas en la capa de salida
            int features = 609;//numero de caracteristicas


            /////////////////////////Lectura maximos///////////////////////////
            maximos = extract(@"C:\maximos.csv", 1, 608);//extraelos datos del csv

            /////////////////////////Lectura minimos///////////////////////////
            minimos = extract(@"C:\minimos.csv", 1, 608);//extraelos datos del csv
    
            /////////////////////////Lectura pesos entrada///////////////////////////
            weightsInput = extract(@"C:\pesosCapaOculta.csv", 50, 609);//extraelos datos del csv

            ////////////////////////Lectura pesos salida//////////////////////////////  

            weightsOutput = extract(@"C:\pesosNeuronaSalida.csv", 1, 51);//extraelos datos del csv
            weightsOutput[0, 0] = 0.105275689656443;//organiza el peso para el bias

            ////////////////////////Lectura Datos entrada////////////////////////////// 
            Input = extract(@"C:\entradasDeLaRed.csv", 300, 609);//extraelos datos del csv

                       ////////////////////////Lectura Datos salida////////////////////////////// 
            Output = extract(@"C:\YdatosPrueba.csv", 300, 1);

                      
            int error=0;//variable para acumular el numero de errores

            for (int i = 0; i < examples; i++)
            {
                Calc_Activation(i, weightsInput, weightsOutput, hidden, output, hiddenNeurons, outputNeurons, Input, features, biasHidden, biasOut,maximos,minimos
                    );//halla la salida de la red para cada ejemplo
                           
              if (output[0] >= 0.9) output[0] = 1;//limitador duro
              if (output[0] < 0.9) output[0] = 0;//limitador duro

             
              if (output[0] != Output[i, 0])
              {
                  error = error + 1;//si la salida no coincide con la esperada
                 // Console.WriteLine(output[0]);
                //  Console.WriteLine(Output[i, 0]);
              }

                for(int j=0; j<50;j++)hidden[j]=0;
                for (int j = 0; j < 1; j++) output[j] = 0;

            }



            Console.WriteLine("errores de clasificacion");
            Console.WriteLine(error);//solo es para comprobar
            Console.ReadLine();//espera hasta que se presione una tecla

        }



    /***************************************************************************************************
    Metodos
    Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
    Descripcion: Extrae en variales informacion de un csv

    ***************************************************************************************************/
        static public double[,] extract(String ruta,int filas, int columnnas)
        {
            var reader = new StreamReader(File.OpenRead(ruta));//archivo csv 
            int fila = 0;//contador para filas de matriz
            double[,] weightsInput = new double[filas, columnnas];//Matriz donde van numeros

            while (!reader.EndOfStream)
            {

                var line = reader.ReadLine();//lee linea a linea el archivo
                var values = line.Split(';');//separa la linea por ; entre palabras

                int contador = 0;//contador para columnas de matriz

                foreach (var value in values)
                {

                    weightsInput[fila, contador] = Convert.ToDouble(value);//asigna a la matriz un double que extrae de un string
                    contador = contador + 1;

                }
                fila = fila + 1;
               
                
            }

            return weightsInput;

        }



      /***************************************************************************************************
      Metodos
      Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
      Descripcion: Evalua la entrada en la funcion especificada

     ***************************************************************************************************/
        static private double sigmoid(double x)
        {

            ///tansig(n) = 2 / (1 + Math.Exp(-2 * n)) - 1;
            return (2 / (1 + Math.Exp(-2 * (double)x))) - 1;
        }


        /***************************************************************************************************
        Metodos
        Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
        Descripcion: Calcula la salida de una red neuronal de 1 capa oculta

        ***************************************************************************************************/

        static private void Calc_Activation(int train, double[,] weightsInput, double[,] weightsOutput, List<double> hidden, List<double> output, int hiddenNeurons, int outputNeurons, double[,] inputsToNetwork, int features, double[,] biasHidden, double biasOut, double[,] maximos, double[,] minimos)
        {
            // Iteración entre el conjunto de activaciones en la capa oculta.
            
            for (int ch = 0; ch < hiddenNeurons ; ch++ )//ch son las neuronas en la capa oculta
            {

                
                for (int ci = 0; ci < features; ci++){//ci son las caracteristicas

                    if (ci < 608  && ci>0)//esto es para la normalizacion, se salta la entrada 0 que es donde esta el bias
                    {
                        inputsToNetwork[train, ci ] = (inputsToNetwork[train, ci] - minimos[0, ci - 1]) / (maximos[0, ci - 1] - minimos[0, ci - 1]);
                    }

                    hidden[ch] +=   inputsToNetwork[train, ci] * weightsInput[ch, ci];//para cada neurona ch acumula las entradas ci
                    
                 }
               
                

            }

            
            // calcular la salida de la capa oculta
            for (int x = 0; x < hiddenNeurons ; x++)
            {
                hidden[x] = sigmoid(hidden[x]);//evalua en la sigmoide
            }

           
            // Iteración entre el conjunto de activaciones en la capa de salida.
            int co = 0;
            while (co < outputNeurons )
            {
                for (int chi = 1; chi < hiddenNeurons  + 1 ; chi++)//sera desde 1 para no multiplicar el bias
                    output[co] += hidden[chi-1] * weightsOutput[co, chi];//para cada neurona co acumula las entradas chi
                output[co] += weightsOutput[co, 0];//suma a la neurona de salida el valor del bias de salida
                co++;

            }
            // Calcular la salida de la capa de Salida
            for (int x = 0; x < outputNeurons; x++)
            {
                             
                output[x] = sigmoid(output[x]);//evalua en la sigmoide
                
            }
        } 

    }
}
