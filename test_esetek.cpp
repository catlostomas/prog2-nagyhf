
#include "test_esetek.hpp"

void Test::futtatas() {
// helyes filename - vonatokBeolvasasa
    TEST(NoThrow, VonatokBeolvasasa){
        Fajl file;
        DinTomb<Vonat> vonatok;
        String test = "vonatok.txt";
        try {
            file.beolvasVonatok(test.c_str(), vonatok);
            EXPECT_NO_THROW("Nem jott kivetel");
        } catch (std::runtime_error & err) {}
    } END;
// helytelen filename - vonatokBeolvasasa
    TEST(Throw, VonatokBeolvasasa){
        Fajl file;
        DinTomb<Vonat> vonatok;
        String test = "random123456789.txt";
        try {
            file.beolvasVonatok(test.c_str(), vonatok);
            EXPECT_THROW(test, std::runtime_error);
        } catch(std::runtime_error & err) {}
    } END;
// helyes filename - jegyekBeolvasasa
    TEST(NoThrow, JegyekBeolvasasa){
        Fajl file;
        DinTomb<Jegy> jegyek;
        String test = "jegyek.txt";
        try {
            file.beolvasJegyek(test.c_str(), jegyek);
            EXPECT_NO_THROW();
        } catch (std::runtime_error& err) {}
    } END;
// helytelen filename - jegyekBeolvasasa
    TEST(Throw, JegyekBeolvasasa){
        Fajl file;
        DinTomb<Jegy> jegyek;
        String test = "random123456789.txt";
        try {
            file.beolvasJegyek(test.c_str(), jegyek);
            EXPECT_THROW(test, std::runtime_error);
        } catch (const std::runtime_error& err) {};
    } END;


// VONATOK - Konstruktorok

// default construktor
    TEST(Default_Construktor, VonatClass){
        Vonat test;
        EXPECT_EQ(strcmp(test.get_Vonatszam().c_str(), ""), 0);
        EXPECT_EQ(strcmp(test.get_indAll().c_str(), ""), 0);
        EXPECT_EQ(strcmp(test.get_erkAll().c_str(), ""), 0);
        EXPECT_TRUE(test.get_indIdo().ora == 0 && test.get_indIdo().perc == 0);
        EXPECT_TRUE(test.get_erkIdo().ora == 0 && test.get_erkIdo().perc == 0);
        EXPECT_TRUE(test.getKeses() == 0);
        EXPECT_TRUE(test.getKocsiDB() == 0);
    } END;
// parameteres construktor
    TEST(Param_Construktor, VonatClass){
        Ido ind (12, 12);
        Ido erk (13, 13);
        Vonat test("vonatszam", "ind_allomas", "erk_allomas", ind, erk, 60, 5);
        EXPECT_EQ(strcmp(test.get_Vonatszam().c_str(), "vonatszam"), 0);
        EXPECT_EQ(strcmp(test.get_indAll().c_str(), "ind_allomas"), 0);
        EXPECT_EQ(strcmp(test.get_erkAll().c_str(), "erk_allomas"), 0);
        EXPECT_TRUE(test.get_indIdo().ora == ind.ora && test.get_indIdo().perc == ind.perc);
        EXPECT_TRUE(test.get_erkIdo().ora == erk.ora && test.get_erkIdo().perc == erk.perc);
        EXPECT_TRUE(test.getKeses() == 60);
        EXPECT_TRUE(test.getKocsiDB() == 5);
    } END;
// masolo konstruktor
    TEST(Copy_Construktor, VonatClass){
        Ido ind (12, 12);
        Ido erk (13, 13);
        Vonat test("vonatszam", "ind_allomas", "erk_allomas", ind, erk, 60, 5);
        Vonat test2 = test;
        EXPECT_EQ(strcmp(test.get_Vonatszam().c_str(), test2.get_Vonatszam().c_str()), 0);
        EXPECT_EQ(strcmp(test.get_indAll().c_str(), test2.get_indAll().c_str()), 0);
        EXPECT_EQ(strcmp(test.get_erkAll().c_str(), test2.get_erkAll().c_str()), 0);
        EXPECT_TRUE(test.get_indIdo().ora == test2.get_indIdo().ora && test.get_indIdo().perc == test2.get_indIdo().perc);
        EXPECT_TRUE(test.get_erkIdo().ora == test2.get_erkIdo().ora && test.get_erkIdo().perc == test2.get_erkIdo().perc);
        EXPECT_TRUE(test2.getKeses() == test.getKeses());
        EXPECT_TRUE(test2.getKocsiDB() == test.getKocsiDB());
    } END;

// JEGYEK - KONSTRUKTOROK

// default konstruktor
    TEST(Default_Construktor, JegyClass){
        Jegy test;
        EXPECT_EQ(strcmp(test.getVsz().c_str(), ""), 0);
        EXPECT_EQ(strcmp(test.getIndAll().c_str(), ""), 0);
        EXPECT_EQ(strcmp(test.getErkAll().c_str(), ""), 0);
        EXPECT_TRUE(test.getIndIdo().ora == 0 && test.getIndIdo().perc == 0);
        EXPECT_TRUE(test.getErkIdo().ora == 0 && test.getErkIdo().perc == 0);
        EXPECT_TRUE(test.getKocsiszam() == 0);
        EXPECT_TRUE(test.getHelyszam() == 0);
        EXPECT_TRUE(test.getKocsiszam() == 0);
    } END;
// parameteres konstruktor
    TEST(Param_Constructor, JegyClass){
        Ido ind(12, 12);
        Ido erk(13, 13);
        Jegy test("ind_all", "erk_all", ind, erk, "vonatszam", 1, 1, 1);
        EXPECT_EQ(strcmp(test.getVsz().c_str(), "vonatszam"), 0);
        EXPECT_EQ(strcmp(test.getIndAll().c_str(), "ind_all"), 0);
        EXPECT_EQ(strcmp(test.getErkAll().c_str(), "erk_all"), 0);
        EXPECT_TRUE(test.getIndIdo().ora == ind.ora && test.getIndIdo().perc == ind.perc);
        EXPECT_TRUE(test.getErkIdo().ora == erk.ora && test.getErkIdo().perc == erk.perc);
        EXPECT_TRUE(test.getKocsiszam() == 1);
        EXPECT_TRUE(test.getHelyszam() == 1);
        EXPECT_TRUE(test.getKocsiszam() == 1);
    } END;

// DINAMIKUS TOMB

// Indexeles testek
    TEST(HelyesIDX, DinTomb){
        DinTomb<int> test;
        test.push_back(1);
        try {
            test[1] = 0;
            EXPECT_NO_THROW(test);
        } catch (std::out_of_range& err) {};
    } END;

    TEST(RosszIDX, DinTomb){
        DinTomb<int> test;
        test.push_back(1);
        try {
            test[2] = 0;
            EXPECT_THROW(test, std::out_of_range);
        } catch (std::out_of_range & err) {};
    } END;

// Elem torlese

    TEST(BenneVanTorles, DinTomb){
        DinTomb<int> test;
        test.push_back(1);
        try{
            test.del_element(1);
            EXPECT_NO_THROW(test);
        } catch (std::runtime_error& err) {};
    } END;

    TEST(NincsBenneTorles, DinTomb){
        DinTomb<int> test;
        test.push_back(1);
        try {
            test.del_element(2);
            EXPECT_THROW(test, std::runtime_error);
        } catch (std::runtime_error& err) {};
    } END;

// Menu tesztek

// Uj vonat teszt
    TEST(UjVonat, MenuClass){
        std::istringstream input(
            "vonatszam\n"
            "ind_allomas\n"
            "erk_allomas\n"
            "12 12\n"
            "13 13\n"
            "1\n"
            "10\n" 
        );
        std::ostringstream output;
        std::streambuf* cinBuf = std::cin.rdbuf();
        std::streambuf* coutBuf = std::cout.rdbuf();
        std::cin.rdbuf(input.rdbuf());
        std::cout.rdbuf(output.rdbuf());
        Menu menu;
        menu.uj_vonat();
        std::cin.rdbuf(cinBuf);
        std::cout.rdbuf(coutBuf);
        std::string vartOutput = 
            "Adja meg a vonatszamot:\n"
            "Honnan? \n"
            "Hova? \n"
            "Adja meg az indulas idejet (ora perc) \n"
            "Adja meg az erkezest idejet (ora perc) \n"
            "Adja meg, hogy hany kocsibol all a vonat? \n"
            "Adja meg, hogy hany hely van egy kocsiban\n"
            "Uj vonat hozzaadva!\n";

        EXPECT_TRUE(output.str().find(vartOutput) != std::string::npos);
        Vonat uj = menu.getVonat(0);
        EXPECT_EQ(uj.get_Vonatszam(), "vonatszam");
        EXPECT_EQ(uj.get_indAll(), "ind_allomas");
        EXPECT_EQ(uj.get_erkAll(), "erk_allomas");
        EXPECT_TRUE(uj.get_indIdo().ora == 12 && uj.get_indIdo().perc == 12);
        EXPECT_TRUE(uj.get_erkIdo().ora == 13 && uj.get_erkIdo().perc == 13);
        EXPECT_EQ(uj.getKocsiDB(), 1);
        EXPECT_EQ(uj.getKocsi(0).get_helyDB(), 10);
    } END;

// Vonat torlese
    TEST(VonatTorlese, MenuClass){
        std::istringstream vonatIN(
            "vonatszam\n"
            "ind_allomas\n"
            "erk_allomas\n"
            "12 12\n"
            "13 13\n"
            "1\n"
            "10\n"
        );
        std::istringstream torlesIN(
            "vonatszam\n"
            "1\n"
        );
        std::ostringstream out;
        std::streambuf* cinBuf = std::cin.rdbuf();
        std::streambuf* coutBuf = std::cout.rdbuf();
        std::cin.rdbuf(vonatIN.rdbuf());
        std::cout.rdbuf(out.rdbuf());
        Menu menu;
        menu.uj_vonat();
        std::cin.rdbuf(torlesIN.rdbuf());
        menu.vonat_torlese();
        std::cin.rdbuf(cinBuf);
        std::cout.rdbuf(coutBuf);
        EXPECT_TRUE(out.str().find("Adja meg a keresett vonat szamat") != std::string::npos);
        EXPECT_TRUE(out.str().find("Ha mindent rendben talal akkor irjon be 1-et, ha nem akkor 0-t") != std::string::npos);
        EXPECT_TRUE(out.str().find("vonatszam vonat torolve") != std::string::npos);
        EXPECT_EQ(menu.getVonatok().getSiz(), 0);
    } END;

// UjJegy teszt
    TEST(UjJegy, MenuClass){
        Menu menu;
        std::istringstream vonatIN(
            "vonatszam\n"
            "ind_allomas\n"
            "erk_allomas\n"
            "12 12\n"
            "13 13\n"
            "1\n"
            "10\n"
        );
        std::ostringstream vonatOut;
        std::streambuf* eredetiOut = std::cout.rdbuf();
        std::cout.rdbuf(vonatOut.rdbuf());
        std::streambuf* eredetiIN = std::cin.rdbuf();
        std::cin.rdbuf(vonatIN.rdbuf());
        menu.uj_vonat();
        std::istringstream jegyIN(
            "vonatszam\n"
            "1\n"
            "1\n"
        );
        std::ostringstream jegyOut;
        std::cin.rdbuf(jegyIN.rdbuf());
        std::cout.rdbuf(jegyOut.rdbuf());
        menu.foglal();
        std::cin.rdbuf(eredetiIN);
        std::cout.rdbuf(eredetiOut);
        EXPECT_TRUE(jegyOut.str().find("Adja meg a vonatszamot:") != std::string::npos);
        EXPECT_TRUE(jegyOut.str().find("1 kocsi van a vonaton") != std::string::npos);
        EXPECT_TRUE(jegyOut.str().find("Melyik helyet szeretne lefoglalni") != std::string::npos);
        EXPECT_TRUE(jegyOut.str().find("hely a") != std::string::npos);
        EXPECT_TRUE(jegyOut.str().find("kocsiban lefoglalva!") != std::string::npos);
        EXPECT_EQ(menu.getJegyek().getSiz(), 1);
        Jegy jegy = menu.getJegy(0);
        EXPECT_EQ(jegy.getVsz(), "vonatszam");
    } END;

// Keses teszt
    TEST(SetKeses, MenuClass){
        Menu menu;
        std::istringstream vonatIN(
            "vonatszam\n"
            "ind_allomas\n"
            "erk_allomas\n"
            "12 12\n"
            "13 13\n"
            "1\n"
            "10\n"
        );
        std::ostringstream vonatOUT;
        std::streambuf* eredetiOUT = std::cout.rdbuf();
        std::cout.rdbuf(vonatOUT.rdbuf());
        std::streambuf* eredetiIN = std::cin.rdbuf();
        std::cin.rdbuf(vonatIN.rdbuf());
        menu.uj_vonat();
        std::cin.rdbuf(eredetiIN);
        std::cout.rdbuf(eredetiOUT);
        std::istringstream kesesIN(
            "vonatszam\n"
            "30\n"
        );
        std::ostringstream kesesOUT;
        std::cout.rdbuf(kesesOUT.rdbuf());
        std::cin.rdbuf(kesesIN.rdbuf());
        menu.keses_beallit();
        std::cin.rdbuf(eredetiIN);
        std::cout.rdbuf(eredetiOUT);
        EXPECT_TRUE(kesesOUT.str().find("Adja meg a keresett vonat szamat") != std::string::npos);
        EXPECT_TRUE(kesesOUT.str().find("Aktualis kesese a vonatnak:") != std::string::npos);
        EXPECT_TRUE(kesesOUT.str().find("Mennyire szeretne a kesest beallitani?") != std::string::npos);
        EXPECT_TRUE(kesesOUT.str().find("A keses atallitva 30 percre") != std::string::npos);
        Vonat vonat = menu.getVonat(0);
        EXPECT_EQ(vonat.getKeses(), 30);
    } END;

// Vonat adatainak keresese
    TEST(VonatAdatainakKeresese, MenuClass){
        Menu menu;
        std::istringstream vonatIN(
            "vonatszam\n"
            "ind_allomas\n"
            "erk_allomas\n"
            "12 12\n"
            "13 13\n"
            "1\n"
            "10\n"
        );
        std::ostringstream vonatOUT;
        std::streambuf* eredetiCOUT = std::cout.rdbuf();
        std::cout.rdbuf(vonatOUT.rdbuf());
        std::streambuf* eredetiCIN;
        std::cin.rdbuf(vonatIN.rdbuf());
        menu.uj_vonat();
        std::cin.rdbuf(eredetiCIN);
        std::cout.rdbuf(eredetiCOUT);

        std::istringstream keresIN(
            "vonatszam\n"
        );
        std::ostringstream keresOUT;
        std::cin.rdbuf(keresIN.rdbuf());
        std::cout.rdbuf(keresOUT.rdbuf());
        menu.vonatAdatok();
        std::cin.rdbuf(eredetiCIN);
        std::cout.rdbuf(eredetiCOUT);
        EXPECT_TRUE(keresOUT.str().find("Adja meg a keresett vonat szamat") != std::string::npos);
        EXPECT_TRUE(keresOUT.str().find("Vonatszam: vonatszam") != std::string::npos);
        EXPECT_TRUE(keresOUT.str().find("Indulasi allomas: ind_allomas") != std::string::npos);
        EXPECT_TRUE(keresOUT.str().find("Erkezesi allomas: erk_allomas") != std::string::npos);
    } END;
}

