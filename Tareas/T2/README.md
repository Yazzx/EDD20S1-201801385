# Especificación Informal

- Freya: las operaciones son verDueño, cambiarDueño.
- Descripción: los valores del TDA Freya son monedas digitales de cantidad y propiedades estáticas e inmutables a través del tiempo
- Operaciones:
    *  verDueño (dueño: Int) devuelve (Int)
       + requerimentos: dueño >= 0
       + efecto: devuelve un numero entero cuyo valor representa el ID del dueño de la Freya específica que se consulta
    * cambiarDueño (dueñoPrimero, dueñoSegundo: Int) devuelve (Int)
       + requerimentos: dueñoPrimero ≠ dueñoSegundo, dueñoPrimero >= 0, dueñoSegundo >= 0
       + efecto: cambia la propiedad dueño de la Freya y devuelve el entero cuyo valor representa el ID del nuevo dueño de la Freya.