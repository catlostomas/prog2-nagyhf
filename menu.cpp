#include "menu.hpp"

void Menu::show() const{
    std::cout << "[1] Vonat adatainak keresese" << std::endl;
    std::cout << "[2] Jegy vasarlas" << std::endl;
    std::cout << "[3] Admin felulet" << std::endl;
    std::cout << "[4] Kilepes es mentes" << std::endl;
}

void Menu::showAdmin() const{
    std::cout << "[1] Uj vonat hozzaadasa" << std::endl;
    std::cout << "[2] Vonat torlese" << std::endl;
    std::cout << "[3] Keses beallitasa" << std::endl;
    std::cout << "[4] Visszalepes" << std::endl;
}

void Menu::showLogo() const{
    // ASCII vonat forras : https://www.asciiart.eu/vehicles/trains
    std::cout << std::endl;
    std::cout << "___________   _______________________________________^__ " << std::endl;
    std::cout << " ___   ___ |||  ___   ___   ___    ___ ___  |   __  ,----\\ " << std::endl;
    std::cout << "|   | |   |||| |   | |   | |   |  |   |   | |  |  | |_____\\ " << std::endl;
    std::cout << "|___| |___|||| |___| |___| |___|  | O | O | |  |  |        \\ " << std::endl;
    std::cout << "           |||                    |___|___| |  |__|         ) " << std::endl;
    std::cout << "___________|||______________________________|______________/ " << std::endl;
    std::cout << "           |||                                        /-------- " << std::endl;
    std::cout << "-----------'''---------------------------------------' " << std::endl;
    std::cout << "            VASUTI JEGYFOGLALASI RENDSZER               \n";
    std::cout << std::endl;

}

int Menu::get_func(){
    int pick = 0;
    std::cin >> pick;
    if (pick < 0 || pick >= 5){
        throw std::out_of_range("Nem letezo funkciot szeretne hasznalni");
    }
    return pick;
}

void Menu::mainloop(){
    try {
        Fajl::beolvasVonatok("vonatok.txt", vonatok);
        Fajl::beolvasJegyek("jegyek.txt", jegyek);
    } catch (std::runtime_error &err){
        std::cout << "HIBA: " << err.what() << std::endl;
    }
    showLogo();
    bool mainloop = true;
    do {
        show();
        int choice = get_func();
        switch (choice) {
            case 1:
                vonatAdatok();
                break;
            case 2:
                foglalVegallomasok();
                break;
            case 3:
                try{
                    AdminMainloop();
                } catch (std::out_of_range& err){
                    std::cout << err.what() << std::endl;
                }
                break;
            case 4:
                Fajl::mentesJegyek("jegyek.txt", jegyek);
                Fajl::mentesVonatok("vonatok.txt", vonatok);
                return;
            default:
                throw std::out_of_range("Nem letezo funkciot szeretne hasznalni");
        }
    }
    while (mainloop);
    Fajl::mentesJegyek("jegyek.txt", jegyek);
    Fajl::mentesVonatok("vonatok.txt", vonatok);
    return;
}

void Menu::uj_vonat(){
    clear();
    String vsz, ind_all, erk_all;
    int ind_ora, ind_perc, erk_ora, erk_perc, kocsiDB;
    size_t HelyKocsiban;
    std::cout << "Kerem adja meg a vonatszamot!" << std::endl;
    std::cin >> vsz;
    std::cin.ignore();
    try{
        for (size_t i = 0; i < vonatok.getSiz(); i++){
            if (vonatok[i].get_Vonatszam() == vsz){
                throw std::runtime_error("Ez a vonatszam mar a rendszerben van!");
            }
        }
    } catch (std::runtime_error& err){
        std::cout << err.what() << std::endl;
        return;
    }

    std::cout << "Honnan? " << std::endl;
    std::string temp_ind_all;
    std::getline(std::cin, temp_ind_all);
    ind_all = temp_ind_all.c_str();
    std::cout << "Hova? " << std::endl;
    std::string temp_erk_all;
    std::getline(std::cin, temp_erk_all);
    erk_all = temp_erk_all.c_str();
    std::cout << "Kerem adja meg az indulas idopontjat (ora perc alakban) !" << std::endl;
    std::cin >> ind_ora >> ind_perc;
    if ((ind_ora < 0 || ind_ora > 23) || (ind_perc < 0 || ind_perc > 59)){
        throw std::out_of_range("Hibas ido!");
    }
    std::cout << "Kerem adja meg az erkezes idopontjat (ora perc alakban) !" << std::endl;
    std::cin >> erk_ora >> erk_perc;
    if ((erk_ora < 0 || erk_ora > 23) || (erk_perc < 0 || erk_perc > 59)){
        throw std::out_of_range("Hibas ido!");
    }
    Ido ind_ido(ind_ora, ind_perc);
    Ido erk_ido(erk_ora, erk_perc);
    std::cout << "Kerem adja meg kocsik szamat! " << std::endl;
    std::cin >> kocsiDB;
    std::cout << "Kerem adja meg hany hely van egy kocsiban!" << std::endl;
    std::cin >> HelyKocsiban;
    Vonat ujVonat(vsz, ind_all, erk_all, ind_ido, erk_ido, 0, kocsiDB, HelyKocsiban);
    vonatok.push_back(ujVonat);
    std::cout << vsz << " vonat sikeresen letrehozva!" << std::endl;
}

size_t Menu::vonat_idx_keres(const String& vsz){
    size_t siz = vonatok.getSiz();
    for (size_t i = 0; i < siz; i++){
        if (vonatok[i] == vsz){
            return i;
        }
    }
    throw std::out_of_range("Nem talalhato ilyen vonatszam a rendszerben!");
}

void Menu::vonat_torlese(){
    clear();
    String keresett;
    size_t idx;
    std::cout << "Kerem adja meg a vonat szamat! " << std::endl;
    std::cin >> keresett;
    try{
        idx = vonat_idx_keres(keresett);
    } catch (std::out_of_range& err){
        std::cout << err.what() << std::endl;
        return;
    }
    vonatok[idx].print();
    std::cout << "Ha mindent rendben talal, akkor kerem irjon be 1-et, ha nem akkor 0-t!" << std::endl;
    bool ok = false;
    std::cin >> ok;
    if (ok){
        vonatok.del_element(vonatok[idx]);
        int torolt_jegyek = 0;
        for (size_t i = 0; i < jegyek.getSiz(); i++){
            if (jegyek[i].getVsz() == keresett){
                jegyek.del_element(jegyek[i]);
                torolt_jegyek++;
            }
        }
        std::cout << keresett << " vonat torolve es a hozza tartozo " << torolt_jegyek << " jegy torolve!" << std::endl;
        return;
    } else {
        std::cout << "Az adatok nem torlodtek!" << std::endl;
        return;
    }
}

void Menu::keses_beallit(){
    clear();
    String keresett;
    size_t idx;
    std::cout << "Kerem adja meg a vonat szamat! " << std::endl;
    std::cin >> keresett;
    try{
        idx = vonat_idx_keres(keresett);
    } catch (std::out_of_range& err){
        std::cout << err.what() << std::endl;
        return;
    }
    std::cout << "A " << vonatok[idx].get_Vonatszam() << " vonat aktualis kesese: " << vonatok[idx].getKeses() << std::endl;
    std::cout << "Kerem adja meg mennyire szeretne a kesest beallitani!" << std::endl;
    int uj_keses = 0;
    std::cin >> uj_keses;
    vonatok[idx].setKeses(uj_keses);
    std::cout << "A keses atallitva " << uj_keses << " percre" << std::endl;
    return;
}

int Menu::randomJegyID(){
    srand(time(0));
    int randomNum = rand() % 100000;
    return randomNum;
}

Vonat Menu::getVonat(size_t idx) const{
    if (idx >= vonatok.getSiz()){
        throw std::out_of_range("Rossz index");
    }
    return vonatok[idx];
}

void Menu::vonatAdatok(){
    clear();
    String keresett_vonatszam;
    std::cout << "Kerem adja meg a vonat szamat!" << std::endl;
    std::cin >> keresett_vonatszam;
    size_t idx = 0;
    try {
        idx = vonat_idx_keres(keresett_vonatszam);
        Vonat keresett = getVonat(idx);
        keresett.print();
    } catch (std::out_of_range& err){
        std::cout << err.what() << std::endl;
        return;
    }
    return;
}

void Menu::AdminMainloop(){
    clear();
    std::cout << "Admin felulet" << std::endl;
    bool mainloop = true;
    do {
        showAdmin();
        int choice = get_func();
        switch (choice) {
            case 1:
                uj_vonat();
                break;
            case 2:
                vonat_torlese();
                break;
            case 3:
                keses_beallit();
                break;
            case 4:
                return;
            default:
                throw std::out_of_range("Nem letezo funkciot akar hasznalni!");
        }
    }
    while (mainloop);
}

Jegy Menu::getJegy(size_t idx) const{
    return jegyek[idx];
}

const DinTomb<Jegy>& Menu::getJegyek() const{
    return jegyek;
}

const DinTomb<Vonat>& Menu::getVonatok() const{
    return vonatok;
}

void Menu::foglal(size_t idx){
    size_t kocsiszam;
    int helyszam;
    std::cout << vonatok[idx].getKocsiDB() << " kocsi van a vonaton. Melyik kocsiban szeretne helyet foglalni? " << std::endl;
    std::cin >> kocsiszam;
    if (kocsiszam <= 0 || kocsiszam > vonatok[idx].getKocsiDB()){
        throw std::out_of_range("Nem letezo kocsiban szeretne helyet foglalni!");
    }
    //                             indexeles 0-val kezdodik
    std::cout << vonatok[idx].getKocsi(kocsiszam - 1).getSzabadHely() << " hely van a kocsiban. Melyik helyet szeretne foglalni?" << std::endl;
    std::cin >> helyszam;
    if (helyszam <= 0 || helyszam > vonatok[idx].getKocsi(kocsiszam - 1).get_helyDB()){
        throw std::out_of_range("Nem letezo helyet szeretne foglalni!");
    }
    //                                         indexeles 0-val kezdodik
    if (vonatok[idx].getKocsi(kocsiszam - 1).get_hely(helyszam - 1).getFoglalt()){
        throw std::runtime_error("Mar foglalt a hely!");
    }
    vonatok[idx].getKocsi(kocsiszam - 1).foglal_hely(helyszam - 1);
    // a vonat adatait atmasolja a jegy adatai koze
    Jegy uj_jegy(vonatok[idx].get_indAll(), vonatok[idx].get_erkAll(), vonatok[idx].get_indIdo(), vonatok[idx].get_erkIdo(), vonatok[idx].get_Vonatszam(), kocsiszam, helyszam, randomJegyID());
    jegyek.push_back(uj_jegy);
    uj_jegy.print();
    std::cout << helyszam << " hely a " << kocsiszam << " kocsiban lefoglalva!" << std::endl;
    return;
}

void Menu::foglalVegallomasok(){
    clear();
    String ind_all, erk_all;
    // ha maradna egy \n beirva
    if (std::cin.peek() == '\n'){
        std::cin.ignore();
    }
    std::cout << "Honnan?" << std::endl;
    std::string temp_ind_all;
    std::getline(std::cin, temp_ind_all);
    ind_all = temp_ind_all.c_str();
    std::cout << "Hova?" << std::endl;
    std::string temp_erk_all;
    std::getline(std::cin, temp_erk_all);
    erk_all = temp_erk_all.c_str();
    size_t talalt_db = 0;
    String pick;
    std::cout << "Vonatok " << ind_all << " es " << erk_all << " kozott:" << std::endl;
    for (size_t i = 0; i < vonatok.getSiz(); i++){
        if (vonatok[i].get_indAll() == ind_all && vonatok[i].get_erkAll() == erk_all){
            std::cout << "[" << talalt_db << "] " << "Vonatszam: " << vonatok[i].get_Vonatszam() << ", indulas: " << vonatok[i].get_indIdo() << ", erkezes: " << vonatok[i].get_erkIdo() << std::endl;
            talalt_db++;
        }
    }
    if (talalt_db == 0){
        std::cout << "Nincs vonat, ami " << ind_all << " es " << erk_all << " kozott kozlekedik!" << std::endl;
        return;
    }
    std::cout << "Kerem adja meg a vonat szamat!" << std::endl;
    std::cin >> pick;
    size_t idx = 0;
    try{
        idx = vonat_idx_keres(pick);
    } catch(std::out_of_range& err){
        std::cout << err.what() << std::endl;
        return;
    }
    try{
        foglal(idx);
    } catch(std::out_of_range& err){
        std::cout << err.what() << std::endl;
    } catch (std::runtime_error& err){
        std::cout << err.what() << std::endl;
    }
    return;

}

void Menu::clear() {
    #ifndef CPORTA
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    #endif
    return;
}

