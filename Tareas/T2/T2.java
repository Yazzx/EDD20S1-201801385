public class T2 {
    
     static int cantidadMonedas = 202;
     // numero aleatorio que sirve para el ejemplo 
     
    public static void main(String args[]) {
    
        Freya[] moneda = new Freya[cantidadMonedas];
        
        for (int i = 0; i<moneda.length ; i++ ){
            moneda[i] = new Freya();
        } 
        
        
        System.out.println("Las monedas han sido creadas :D");
        
        
        // se asume que los dueños de las monedas tienen una id, y que 
        // la id cero pertenece al banco
        // ejemplo
        
        moneda[2].verdueño();
        moneda[3].cambiardueño(125);

        // ver numero de monedas por ID de cliente
        
        int monedas = 0;

        for (int j = 0; j<moneda.length ; j++ ){
            if (moneda[j].dueño == 125) {
                //System.out.println(moneda[j].dueño);
                monedas++;
            }
            
        } 

        System.out.println("Las monedas del cliente 125 son: " + monedas );
      
    }
}


class Freya{
    
    public int dueño;
    
    Freya(){
        int dueñoinicial = 0;
        this.dueño = dueñoinicial;
        // el dueño inicial siempre es el banco
    }
    
   void verdueño(){
      System.out.println("El dueño de esta Freya es: " + dueño); 
   }
    
    void cambiardueño(int nuevo_id){
        System.out.println("El dueño antiguo es: " + dueño);
        this.dueño = nuevo_id;
        
        System.out.println("El nuevo dueño es: " + dueño);
    }
}