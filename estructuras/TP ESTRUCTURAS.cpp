#include <iostream>

using namespace std;

#define CANT_DESTINOS 30
#define CANT_HABITACIONES 60
#define CANT_DESTINOS_REPOSITORIO 97

struct ST_HABITACION
{
    int numero;
    int capacidad;
    char estado;
};

struct ST_HOTEL
{
    string nombre;
    int categoria;
    ST_HABITACION habitaciones[CANT_HABITACIONES];
};

struct ST_DESTINO
{
    string nombre;
    string descripcion;
    string pais;
    char temporada;
    ST_HOTEL hotel;
};

void generarDestinos(ST_DESTINO destinos[CANT_DESTINOS], bool conOcupacion);

struct ST_DESTINO_MAESTRO
{
    string pais;
    string nombre_destino;
    string nombre_hotel;
    int categoria;
    char temporada;
} repositorio[CANT_DESTINOS_REPOSITORIO] = {
    "Italy", "100. Italy, Borgo Egnazia, Savelletri di Fasano", "Borgo Egnazia, Savelletri di Fasano", 4, 'V',
    "South Carolina", "98. South Carolina, (tie) The Spectator Hotel, Charleston", "(tie) The Spectator Hotel, Charleston", 5, 'I',
    "New York City", "98. New York City, (tie) The Lowell", "(tie) The Lowell", 2, 'V',
    "Mexico", "97. Mexico, Vidanta Nuevo Vallarta", "Vidanta Nuevo Vallarta", 3, 'I',
    "China", "96. China, The Temple House, Chengdu", "The Temple House, Chengdu", 5, 'V',
    "Mexico", "95. Mexico, Montage Los Cabos, Cabo San Lucas", "Montage Los Cabos, Cabo San Lucas", 1, 'I',
    "Jamaica", "94. Jamaica, Round Hill Hotel and Villas, Montego Bay", "Round Hill Hotel and Villas, Montego Bay", 5, 'V',
    "London", "93. London, The Milestone Hotel", "The Milestone Hotel", 1, 'I',
    "Costa Rica", "92. Costa Rica, Casa Chameleon at Las Catalinas, Guanacaste", "Casa Chameleon at Las Catalinas, Guanacaste", 1, 'V',
    "Laos", "91. Laos, Belmond La R&eacute;sidence Phou Vao, Luang Prabang", "Belmond La R&eacute;sidence Phou Vao, Luang Prabang", 5, 'I',
    "Bangkok", "90. Bangkok, Lebua at State Tower", "Lebua at State Tower", 2, 'V',
    "Paris", "89. Paris, Le Meurice", "Le Meurice", 4, 'V',
    "Vietnam", "88. Vietnam, Park Hyatt Saigon, Ho Chi Minh City", "Park Hyatt Saigon, Ho Chi Minh City", 1, 'I',
    "United Arab Emirates", "87. United Arab Emirates, Jumeirah at Etihad Towers, Abu Dhabi", "Jumeirah at Etihad Towers, Abu Dhabi", 4, 'I',
    "Tanzania", "86. Tanzania, Ngorongoro Serena Safari Lodge, Ngorongoro Conservation Area", "Ngorongoro Serena Safari Lodge, Ngorongoro Conservation Area", 3, 'V',
    "Costa Rica", "85. Costa Rica, Nayara Gardens, Arenal Volcano National Park", "Nayara Gardens, Arenal Volcano National Park", 4, 'V',
    "California", "84. California, Post Ranch Inn, Big Sur", "Post Ranch Inn, Big Sur", 3, 'I',
    "Peru", "83. Peru, Palacio del Inka, a Luxury Collection Hotel, Cuzco", "Palacio del Inka, a Luxury Collection Hotel, Cuzco", 2, 'I',
    "French Polynesia", "81. French Polynesia, (tie) The St. Regis Bora Bora Resort", "(tie) The St. Regis Bora Bora Resort", 3, 'I',
    "Warsaw", "81. Warsaw, (tie) Hotel Bristol, a Luxury Collection Hotel", "(tie) Hotel Bristol, a Luxury Collection Hotel", 1, 'I',
    "Costa Rica", "80. Costa Rica, Hacienda AltaGracia, Auberge Resorts Collection, P&eacute;rez Zeled&oacute;n", "Hacienda AltaGracia, Auberge Resorts Collection, P&eacute;rez Zeled&oacute;n", 5, 'V',
    "Montana", "79. Montana, Triple Creek Ranch, Darby", "Triple Creek Ranch, Darby", 1, 'I',
    "Greece", "78. Greece, Katikies Hotel, Santorini", "Katikies Hotel, Santorini", 5, 'V',
    "Vietnam", "77. Vietnam, InterContinental Danang Sun Peninsula Resort, Danang", "InterContinental Danang Sun Peninsula Resort, Danang", 3, 'V',
    "Jamaica", "76. Jamaica, Tensing Pen, Negril", "Tensing Pen, Negril", 4, 'I',
    "California", "75. California, Meadowood Napa Valley, St. Helena", "Meadowood Napa Valley, St. Helena", 4, 'V',
    "India", "74. India, The Oberoi Rajvilas, Jaipur", "The Oberoi Rajvilas, Jaipur", 5, 'I',
    "Hawaii", "73. Hawaii, Hotel Wailea, Maui", "Hotel Wailea, Maui", 2, 'V',
    "San Diego", "72. San Diego, Rancho Valencia Resort &amp; Spa", "Rancho Valencia Resort &amp; Spa", 2, 'V',
    "Thailand", "71. Thailand, Six Senses Samui, Koh Samui", "Six Senses Samui, Koh Samui", 2, 'V',
    "St. Lucia", "70. St. Lucia, Jade Mountain", "Jade Mountain", 2, 'V',
    "South Africa", "69. South Africa, Sabi Sabi Private Game Reserve Lodges", "Sabi Sabi Private Game Reserve Lodges", 1, 'I',
    "South Africa", "68. South Africa, andBeyond Phinda Forest Lodge, Phinda Private Game Reserve", "andBeyond Phinda Forest Lodge, Phinda Private Game Reserve", 5, 'V',
    "London", "66. London, (tie) The Lanesborough", "(tie) The Lanesborough", 2, 'I',
    "Illinois", "66. Illinois, (tie) Deer Path Inn, Lake Forest", "(tie) Deer Path Inn, Lake Forest", 5, 'I',
    "South Africa", "65. South Africa, andBeyond Kirkman's Kamp, Sabi Sand Game Reserve", "andBeyond Kirkman's Kamp, Sabi Sand Game Reserve", 3, 'V',
    "Indonesia", "64. Indonesia, Four Seasons Resort Bali at Sayan", "Four Seasons Resort Bali at Sayan", 5, 'I',
    "Hawaii", "63. Hawaii, Montage Kapalua Bay, Maui", "Montage Kapalua Bay, Maui", 5, 'I',
    "Zimbabwe", "62. Zimbabwe, Matetsi Victoria Falls, Matetsi Private Game Reserve", "Matetsi Victoria Falls, Matetsi Private Game Reserve", 2, 'V',
    "Antigua", "61. Antigua, Curtain Bluff", "Curtain Bluff", 2, 'V',
    "Mexico", "55. Mexico, (tie) Viceroy Riviera Maya, Playa del Carmen", "(tie) Viceroy Riviera Maya, Playa del Carmen", 1, 'I',
    "Chile", "55. Chile, (tie) Tierra Atacama Hotel &amp; Spa, San Pedro de Atacama", "(tie) Tierra Atacama Hotel &amp; Spa, San Pedro de Atacama", 1, 'I',
    "Italy", "55. Italy, (tie) Rosewood Castiglion del Bosco, Montalcino", "(tie) Rosewood Castiglion del Bosco, Montalcino", 1, 'I',
    "California", "55. California, (tie) North Block Hotel, Yountville", "(tie) North Block Hotel, Yountville", 4, 'I',
    "Canada", "55. Canada, (tie) Fogo Island Inn, Newfoundland", "(tie) Fogo Island Inn, Newfoundland", 5, 'V',
    "India", "54. India, The Oberoi Amarvilas, Agra", "The Oberoi Amarvilas, Agra", 1, 'V',
    "Virginia", "53. Virginia, The Bristol Hotel, Bristol", "The Bristol Hotel, Bristol", 2, 'I',
    "Thailand", "52. Thailand, Anantara Golden Triangle Elephant Camp &amp; Resort, Chiang Rai", "Anantara Golden Triangle Elephant Camp &amp; Resort, Chiang Rai", 4, 'V',
    "Italy", "51. Italy, Palazzo Avino, Ravello", "Palazzo Avino, Ravello", 3, 'V',
    "Kenya", "50. Kenya, andBeyond Bateleur Camp, Masai Mara National Reserve", "andBeyond Bateleur Camp, Masai Mara National Reserve", 2, 'I',
    "India", "49. India, The Oberoi Udaivilas, Udaipur", "The Oberoi Udaivilas, Udaipur", 1, 'V',
    "Tanzania", "48. Tanzania, Four Seasons Safari Lodge Serengeti, Serengeti National Park", "Four Seasons Safari Lodge Serengeti, Serengeti National Park", 1, 'V',
    "Thailand", "47. Thailand, Anantara Hua Hin Resort, Hua Hin", "Anantara Hua Hin Resort, Hua Hin", 3, 'I',
    "Anguilla", "46. Anguilla, Frangipani Beach Resort", "Frangipani Beach Resort", 3, 'V',
    "New Zealand", "45. New Zealand, Matakauri Lodge, Queenstown", "Matakauri Lodge, Queenstown", 2, 'I',
    "Massachusetts", "44. Massachusetts, The Row Hotel at Assembly Row, Somerville", "The Row Hotel at Assembly Row, Somerville", 5, 'V',
    "Italy", "43. Italy, Grand Hotel Villa Serbelloni, Lake Como", "Grand Hotel Villa Serbelloni, Lake Como", 1, 'V',
    "Peru", "41. Peru, (tie) Sol y Luna, Sacred Valley", "(tie) Sol y Luna, Sacred Valley", 3, 'V',
    "Greece", "41. Greece, (tie) Grace Hotel Santorini, Auberge Resorts Collection", "(tie) Grace Hotel Santorini, Auberge Resorts Collection", 4, 'I',
    "Fiji", "40. Fiji, Six Senses Fiji, Malolo Island", "Six Senses Fiji, Malolo Island", 5, 'V',
    "Indonesia", "39. Indonesia, Nihi Sumba", "Nihi Sumba", 2, 'V',
    "India", "38. India, Taj Lake Palace, Udaipur", "Taj Lake Palace, Udaipur", 1, 'V',
    "Maldives", "37. Maldives, Six Senses Laamu, Olhuveli Island", "Six Senses Laamu, Olhuveli Island", 4, 'I',
    "Texas", "36. Texas, Hotel Eleven, Austin", "Hotel Eleven, Austin", 3, 'I',
    "Mexico", "35. Mexico, Las Ventanas al Para&iacute;so, a Rosewood Resort, San Jos&eacute; del Cabo", "Las Ventanas al Para&iacute;so, a Rosewood Resort, San Jos&eacute; del Cabo", 3, 'I',
    "South Africa", "34. South Africa, Lion Sands Game Reserve, Sabi Sands Game Reserve", "Lion Sands Game Reserve, Sabi Sands Game Reserve", 2, 'V',
    "New Mexico", "33. New Mexico, The Inn of the Five Graces, Santa Fe", "The Inn of the Five Graces, Santa Fe", 5, 'I',
    "South Africa", "32. South Africa, Saxon Hotel, Villas &amp; Spa, Johannesburg", "Saxon Hotel, Villas &amp; Spa, Johannesburg", 1, 'I',
    "Turks and Caicos", "30. Turks and Caicos, The Shore Club", "The Shore Club", 4, 'I',
    "Tanzania", "29. Tanzania, The Highlands, Ngorongoro Conservation Area", "The Highlands, Ngorongoro Conservation Area", 5, 'V',
    "Mexico", "27. Mexico, (tie) Rosewood Mayakoba, Playa del Carmen", "(tie) Rosewood Mayakoba, Playa del Carmen", 3, 'V',
    "Vermont", "27. Vermont, (tie) Rabbit Hill Inn, Lower Waterford", "(tie) Rabbit Hill Inn, Lower Waterford", 4, 'I',
    "Bhutan", "26. Bhutan, Gangtey Lodge, Phobjikha Valley", "Gangtey Lodge, Phobjikha Valley", 5, 'V',
    "Argentina", "25. Argentina, The Vines Resort &amp; Spa, Mendoza", "The Vines Resort &amp; Spa, Mendoza", 2, 'I',
    "Virginia", "24. Virginia, Inn at Willow Grove, Orange", "Inn at Willow Grove, Orange", 1, 'V',
    "Mumbai", "23. Mumbai, The Oberoi", "The Oberoi", 3, 'V',
    "Florence", "22. Florence, J.K. Place Firenze", "J.K. Place Firenze", 3, 'I',
    "Australia", "21. Australia, Southern Ocean Lodge, Kangaroo Island", "Southern Ocean Lodge, Kangaroo Island", 2, 'I',
    "South Africa", "20. South Africa, Londolozi, Sabi Sands Game Reserve", "Londolozi, Sabi Sands Game Reserve", 4, 'V',
    "Mexico", "19. Mexico, The Resort at Pedregal, Cabo San Lucas", "The Resort at Pedregal, Cabo San Lucas", 3, 'V',
    "Mexico", "18. Mexico, Hotel Matilda, San Miguel de Allende", "Hotel Matilda, San Miguel de Allende", 4, 'I',
    "Greece", "17. Greece, Canaves Oia Epitome, Santorini", "Canaves Oia Epitome, Santorini", 1, 'V',
    "Cape Town", "16. Cape Town, Ellerman House", "Ellerman House", 4, 'I',
    "Chile", "15. Chile, Tierra Patagonia, Torres del Paine", "Tierra Patagonia, Torres del Paine", 3, 'V',
    "Thailand", "14. Thailand, Six Senses Yao Noi", "Six Senses Yao Noi", 4, 'V',
    "Fiji", "12. Fiji, (tie) Turtle Island", "(tie) Turtle Island", 3, 'V',
    "Morocco", "12. Morocco, (tie) Royal Mansour, Marrakesh", "(tie) Royal Mansour, Marrakesh", 2, 'V',
    "Costa Rica", "9. Costa Rica, (tie) Lapa Rios Lodge, Osa Peninsula", "(tie) Lapa Rios Lodge, Osa Peninsula", 4, 'V',
    "Zambia", "9. Zambia, (tie) The Bushcamp Company&rsquo;s Mfuwe Lodge, South Luangwa National Park", "(tie) The Bushcamp Company&rsquo;s Mfuwe Lodge, South Luangwa National Park", 5, 'I',
    "Tanzania", "8. Tanzania, Singita Grumeti, Serengeti National Park Area", "Singita Grumeti, Serengeti National Park Area", 3, 'I',
    "Indonesia", "7. Indonesia, The Mulia, Bali", "The Mulia, Bali", 5, 'I',
    "Vietnam", "6. Vietnam, JW Marriott Phu Quoc Emerald Bay Resort &amp; Spa", "JW Marriott Phu Quoc Emerald Bay Resort &amp; Spa", 1, 'V',
    "Tanzania", "5. Tanzania, Gibb's Farm, Karatu", "Gibb's Farm, Karatu", 3, 'I',
    "New Zealand", "4. New Zealand, The Farm at Cape Kidnappers, Hawke's Bay", "The Farm at Cape Kidnappers, Hawke's Bay", 2, 'I',
    "South Africa", "3. South Africa, Singita Sabi Sand, Sabi Sands Game Reserve", "Singita Sabi Sand, Sabi Sands Game Reserve", 4, 'I',
    "Wyoming", "2. Wyoming, The Lodge &amp; Spa at Brush Creek Ranch, Saratoga", "The Lodge &amp; Spa at Brush Creek Ranch, Saratoga", 5, 'I',
    "India", "1. India, The Leela Palace Udaipur", "The Leela Palace Udaipur", 3, 'V'};

int obtenerCapacidad(int i)
{
    int capacidad = 2;

    if (i > 19 && i < 40)
    {
        capacidad = 4;
    }

    if (i >= 40)
    {
        capacidad = 8;
    }

    return capacidad;
}

void inicializaHabitaciones(ST_HABITACION habitaciones[CANT_HABITACIONES], bool conOcupacion)
{
    char estado = 'D';
    for (int i = 0; i < CANT_HABITACIONES; i++)
    {
        if (conOcupacion)
        {
            estado = rand() % 2 ? 'O' : 'D';
        }
        habitaciones[i].numero = i + 1;
        habitaciones[i].estado = estado;
        habitaciones[i].capacidad = obtenerCapacidad(i);
    }
}

bool destinoYaElegido(int pos, int posiciones[CANT_DESTINOS])
{
    int i = 0;
    while (i < CANT_DESTINOS && posiciones[i] != pos)
    {
        i++;
    }
    return i < CANT_DESTINOS;
}

ST_HOTEL generaHotel(ST_DESTINO_MAESTRO destino, bool conOcupacion)
{
    ST_HOTEL hotel;
    hotel.nombre = destino.nombre_hotel;
    hotel.categoria = destino.categoria;
    inicializaHabitaciones(hotel.habitaciones, conOcupacion);
    return hotel;
}

void generarDestinos(ST_DESTINO destinos[CANT_DESTINOS], bool conOcupacion)
{
    int posiciones[CANT_DESTINOS] = {0};

    int pos = 0;
    int i = 0;
    for (int i = 0; i < CANT_DESTINOS; i++)
    {
        pos = rand() % CANT_DESTINOS_REPOSITORIO;
        while (destinoYaElegido(pos, posiciones))
        {
            pos = rand() % CANT_DESTINOS_REPOSITORIO;
        }
        posiciones[i] = pos;

        destinos[i].nombre = repositorio[pos].nombre_destino;
        destinos[i].pais = repositorio[pos].pais;
        destinos[i].temporada = repositorio[pos].temporada;
        destinos[i].descripcion = "";
        destinos[i].hotel = generaHotel(repositorio[pos], conOcupacion);
    }
}
//-------------------------------------------------------

void ocuparHabitacion(ST_DESTINO destino[], ST_HABITACION habitacion[], int cantPasajeros, int posicion)
{
    int i = 0;
    if (cantPasajeros < 3)
    {
        for (i = 0; i < CANT_HABITACIONES; i++)
        {
           if (destino[posicion].hotel.habitaciones[i].estado == 'D' && destino[posicion].hotel.habitaciones[i].capacidad >= cantPasajeros)
           {
               destino[posicion].hotel.habitaciones[i].estado = 'O';
               destino[posicion].hotel.habitaciones[i].capacidad = destino[posicion].hotel.habitaciones[i].capacidad - cantPasajeros;
           }

        }
    }
    if (cantPasajeros > 2 && cantPasajeros < 5)
    {
        for (i = 19; i < CANT_HABITACIONES; i++)
        {
            if (destino[posicion].hotel.habitaciones[i].estado == 'D' && destino[posicion].hotel.habitaciones[i].capacidad >= cantPasajeros)
            {
                destino[posicion].hotel.habitaciones[i].estado = 'O';
                destino[posicion].hotel.habitaciones[i].capacidad = destino[posicion].hotel.habitaciones[i].capacidad - cantPasajeros;
            }
        }
    }
    if (cantPasajeros > 4 && cantPasajeros < 9)
    {
        for (int i = 39; i < CANT_HABITACIONES; i++)
        {
            if (destino[posicion].hotel.habitaciones[i].estado == 'D' && destino[posicion].hotel.habitaciones[i].capacidad >= cantPasajeros)
            {
                destino[posicion].hotel.habitaciones[i].estado = 'O';
                destino[posicion].hotel.habitaciones[i].capacidad = destino[posicion].hotel.habitaciones[i].capacidad - cantPasajeros;
            }
        }
    }
    cout << destino[posicion].hotel.nombre << " fue ocupado en su habitacion " << destino[posicion].hotel.habitaciones[i].numero << " con " << cantPasajeros << " pasajeros." << endl;
}

int buscarDestino(ST_DESTINO destino[], ST_HABITACION habitacion[], string lugar, int cantPasajeros)
{
    int inicio = 0;
    int fin = CANT_DESTINOS - 1;
    int mitad = 0;
    while (fin >= inicio)
    {
        mitad = inicio + (fin - inicio) / 2;

        if (destino[mitad].pais == lugar)
        {
            return mitad;
        }
        if (destino[mitad].pais > lugar)
        {
            fin = mitad - 1;
        }
        else
        {
            inicio = mitad + 1;
        }
    }
    if (mitad > 0)
    {
        ocuparHabitacion(destino, habitacion, cantPasajeros, mitad);
    }
    return -1;
}

void imprimirDestinos(ST_DESTINO destino[]){
    for (int i = 0; i < CANT_DESTINOS; i++)
    {
        cout << destino[i].nombre << endl;
    }
}

void ordenarXDestino(ST_DESTINO destino[], int limite)
{
    int i, j;
    ST_DESTINO aux;
    for (i = 0; i < limite - 1; i++)
    {
        for (j = 0; j < limite - 1 - i; j++)
        {
            if (destino[j].pais > destino[j + 1].pais)
            {
                aux = destino[j];
                destino[j] = destino[j + 1];
                destino[j + 1] = aux;
            }
        }
    }
    imprimirDestinos(destino);
}

void desocuparHabitacion(ST_DESTINO destino[], ST_HABITACION habitacion[], ST_HOTEL hotel[], string lugar, int numHabitacion, int cantPasajeros, int posicionDestino)
{
    destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].capacidad = destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].capacidad + cantPasajeros;
    destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].estado = 'D';
    cout << destino[posicionDestino].hotel.nombre << " fue desocupado en su habitacion " << destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].numero << " y ahora cuenta con una capacidad de para " << destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].capacidad << " pasajeros." << endl;
}

void buscarHabitacion(ST_DESTINO destino[], ST_HABITACION habitacion[], ST_HOTEL hotel[], string lugar, int numHabitacion, int cantPasajeros)
{
    int inicio = 0;
    int fin = CANT_DESTINOS - 1;
    int mitad = 0;
    while (fin >= inicio)
    {
        mitad = inicio + (fin - inicio) / 2;
        if (destino[mitad].nombre == lugar)
        {
            int posicion = mitad;
        }
        if (destino[mitad].nombre > lugar)
        {
            fin = mitad - 1;
        }
        else
        {
            fin = mitad + 1;
        }
    }
    desocuparHabitacion(destino, habitacion, hotel, lugar, numHabitacion, cantPasajeros, mitad);
}

void ordenarXEstacion(ST_DESTINO destino[], ST_HOTEL hotel[], ST_HABITACION habitacion[], char estacion)
{
    int i = 0, j = 0;
    ST_DESTINO aux[3];
    int contadorA = 0;
    int contadorB = 0;
    int contadorC = 0;
    int contadorD = 0;

    for (i = 0; i < CANT_DESTINOS; i++)
    {
        for (j = 0; j < CANT_HABITACIONES; j++)
        {
            if (destino[i].temporada == estacion)
            {
                if (destino[i].hotel.habitaciones[j].estado == 'O')
                {
                    contadorA++;
                }
            }
            if (contadorA > contadorB)
            {
                aux[0] = destino[i];
                contadorB = contadorA;
                contadorA = 0;
            }
            if (contadorA > contadorB)
            {
                aux[1] = destino[i];
                contadorC = contadorA;
                contadorA = 0;
            }
            if (contadorA > contadorB)
            {
                aux[2] = destino[i];
                contadorD = contadorA;
                contadorA = 0;
            }
        }
    }
    cout << "los 3 destinos mas ocupados segun la temporada " << estacion << " son: " << aux[0].pais << ", " << aux[1].pais << " y " << aux[2].pais << endl;
}

int main()
{
    ST_HABITACION habitaciones[CANT_HABITACIONES];
    ST_DESTINO destinos[CANT_DESTINOS];
    ST_HOTEL hoteles[CANT_DESTINOS];
    bool ocupado;
    generarDestinos(destinos, ocupado);
    ordenarXDestino(destinos, CANT_DESTINOS);
    string lugar = " ";
    int cantPasajeros = 0;
    int habitacionOcupada = 0;
    int accion = 0;
    cout << "que es lo que desea realizar?" << endl;
    cout << " 1 ocupar." << endl;
    cout << " 2 desocupar." << endl;
    cout << " 3 otra." << endl;
    cout << " 4 finalizar programa." << endl;
    cin >> accion;
    string estacion = " ";
    while(accion < 4){
    switch (accion)
    {
    case 1:
    {
        cout << "a que lugar desea viajar? ";
        cin >> lugar;
        cout << "cuantas personas ocuparan la habitacion? ";
        cin >> cantPasajeros;
        int ubicacion = buscarDestino(destinos, habitaciones, lugar, cantPasajeros);
    }
    break;
    case 2:
    {
        cout << "a que lugar viajo? ";
        cin >> lugar;
        cout << "que habitacion ocuparon? ";
        cin >> habitacionOcupada;
        cout << "cuantas personas fueron de viaje? ";
        cin >> cantPasajeros;
        buscarHabitacion(destinos, habitaciones, hoteles, lugar, habitacionOcupada, cantPasajeros);
    }
    break;
    case 3:
        cout << "de que temporada quiere conocer su capacidad? (invierno o verano) " << endl;
        cin >> estacion;
        if (estacion == "verano")
        {
            char estacionChar = 'V';
            ordenarXEstacion(destinos, hoteles, habitaciones, estacionChar);
        }
        else
        {
            char estacionChar = 'I';
            ordenarXEstacion(destinos, hoteles, habitaciones, estacionChar);
        }
        break;
    }
        cout << "que es lo que desea realizar?" << endl;
        cout << " 1 ocupar." << endl;
        cout << " 2 desocupar." << endl;
        cout << " 3 otra." << endl;
        cout << " 4 finalizar programa." << endl;
        cin >> accion;
    }
    cout << "programa finalizado.";
    system("pause");
    return 0;
}