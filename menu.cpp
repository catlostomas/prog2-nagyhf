
#include "menu.hpp"

void Menu::show(){
    std::cout << "[1] Uj vonat hozzaadasa" << std::endl;
    std::cout << "[2] Vonat torlese" << std::endl;
    std::cout << "[3] Keses beallitasa" << std::endl;
    std::cout << "[4] Jegy vasarlas" << std::endl;
    std::cout << "[5] Tesztesetek futtatasa" << std::endl;
}

int Menu::get_func(){
    int pick = 0;
    std::cin >> pick;
    if (pick < 0 || pick >= 10){
        throw std::out_of_range("Rossz index");
        return -1;
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
    bool mainloop = true;
    do {
        show();
        int choice = get_func();
        switch (choice) {
            case 0:
                mainloop = false;
                break;
            case 1 :
                uj_vonat();
                break;
            case 2:
                vonat_torlese();
                break;
            case 3:
                keses_beallit();
                break;
            case 4:
                foglal();
                break;
            case 5:
                Test::futtatas();
                return;
                break;
            default:
                throw std::out_of_range("Nem letezo funkciot akar hasznalni");
        }
    }
    while (mainloop);
    Fajl::mentesJegyek("jegyek.txt", jegyek);
    Fajl::mentesVonatok("vonatok.txt", vonatok);
    return;
}

void Menu::uj_vonat(){
    String vsz, ind_all, erk_all;
    int ind_ora, ind_perc, erk_ora, erk_perc, kocsiDB;
    std::cout << "Adja meg a vonatszamot:" << std::endl;
    std::cin >> vsz;
    std::cout << "Honnan? " << std::endl;
    std::cin >> ind_all;
    std::cout << "Hova? " << std::endl;
    std::cin >> erk_all;
    std::cout << "Adja meg az indulas idejet (ora perc) " << std::endl;
    std::cin >> ind_ora >> ind_perc;
    std::cout << "Adja meg az erkezest idejet (ora perc) " << std::endl;
    std::cin >> erk_ora >> erk_perc;
    Ido ind_ido(ind_ora, ind_perc);
    Ido erk_ido(erk_ora, erk_perc);
    std::cout << "Adja meg, hogy hany kocsibol all a vonat? " << std::endl;
    std::cin >> kocsiDB;
    Vonat ujVonat(vsz, ind_all, erk_all, ind_ido, erk_ido, 0, kocsiDB);
    vonatok.push_back(ujVonat);
    std::cout << "Uj vonat hozzaadva: " << std::endl;
}



size_t Menu::vonat_idx_keres(const String& vsz){
    size_t siz = vonatok.getSiz();
    for (size_t i = 0; i < siz; i++){
        if (vonatok[i] == vsz){
            return i;
        }
    }
    return -1;
}



void Menu::vonat_torlese(){
    String keresett;
    size_t idx;
    std::cout << "Adja meg a keresett vonat szamat" << std::endl;
    std::cin >> keresett;
    idx = vonat_idx_keres(keresett);
    if (idx == static_cast<size_t>(-1)){
        std::cout << "nem letezik" << std::endl;
        return;
    }
    vonatok[idx].print();
    std::cout << "Ha mindent rendben talal akkor irjon be 1-et " << std::endl;
    bool ok = false;
    std::cin >> ok;
    if (ok){
        vonatok.del_element(vonatok[idx]);
        std::cout << "Sikeres torles" << std::endl;
        return;
    }
    std::cout << "Sikertelen torles" << std::endl;
    return;
}

void Menu::keses_beallit(){
    String keresett;
    size_t idx;
    std::cout << "Adja meg a keresett vonat szamat" << std::endl;
    std::cin >> keresett;
    idx = vonat_idx_keres(keresett);
    if (idx == static_cast<size_t>(-1)){
        std::cout << "nem letezik";
        return;
    }
    std::cout << "Aktualis kesese a vonatnak: " << vonatok[idx].getKeses() << std::endl;
    std::cout << "Mennyire szeretne a kesest beallitani? " << std::endl;
    int uj_keses = 0;
    std::cin >> uj_keses;
    vonatok[idx].setKeses(uj_keses);
    std::cout << "A keses atallitva " << uj_keses << " percre" << std::endl;
    return;
}

void Menu::foglal(){
    String keresett_vonat;
    size_t idx;
    size_t kocsiszam, helyszam;

    std::cout << "Adja meg a vonatszamot: " << std::endl;
    std::cin >> keresett_vonat;

    idx = vonat_idx_keres(keresett_vonat);
    if (idx == static_cast<size_t>(-1)) {
        std::cout << "Nem letezik a keresett vonat" << std::endl;
        return;
    }
    std::cout << vonatok[idx].getKocsiDB() << " kocsi van a vonaton. Melyik kocsiban szeretne helyet foglalni? " << std::endl;
    std::cin >> kocsiszam;
    if (kocsiszam <= 0 || kocsiszam > vonatok[idx].getKocsiDB()){
        std::cout << "Nem letezik ilyen kocsi" << std::endl;
        return;
    }
    std::cout << vonatok[idx].getKocsi(kocsiszam - 1).getSzabadHely() << " hely van a kocsiban. Melyik helyet szeretne lefoglalni ?" << std::endl;
    std::cin >> helyszam;
    if (helyszam <= 0 || helyszam > vonatok[idx].getKocsi(kocsiszam - 1).get_helyDB()){
        std::cout << "Nem letezik ez a hely" << std::endl;
        return;
    }
    if (vonatok[idx].getKocsi(kocsiszam - 1).get_hely(helyszam - 1).getFoglalt()){
        std::cout << "mar foglalat a hely" << std::endl;
        return;
    }
    vonatok[idx].getKocsi(kocsiszam - 1).foglal_hely(helyszam - 1);
    Jegy uj_jegy(vonatok[idx].get_indAll(), vonatok[idx].get_erkAll(), vonatok[idx].get_indIdo(), vonatok[idx].get_erkIdo(), vonatok[idx].get_Vonatszam(), kocsiszam, helyszam, randomJegyID());
    jegyek.push_back(uj_jegy);
    uj_jegy.print();
    std::cout << "sikeres foglalas" << std::endl;
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

