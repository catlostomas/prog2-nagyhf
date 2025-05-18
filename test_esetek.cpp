
#include "test_esetek.hpp"

void Test::futtatas() {
// helyes filename - vonatokBeolvasasa
    TEST(NoThrow, VonatokBeolvasasa){
        DinTomb<Vonat> vonatok;
        String test = "vonatok.txt";
        EXPECT_NO_THROW(Fajl::beolvasVonatok(test.c_str(), vonatok));
    } END;
// helytelen filename - vonatokBeolvasasa
    TEST(Throw, VonatokBeolvasasa){
        DinTomb<Vonat> vonatok;
        String test = "random123456789.txt";
        EXPECT_THROW(Fajl::beolvasVonatok(test.c_str(), vonatok), std::runtime_error);
    } END;
// helyes filename - jegyekBeolvasasa
    TEST(NoThrow, JegyekBeolvasasa){
        DinTomb<Jegy> jegyek;
        String test = "jegyek.txt";
        EXPECT_NO_THROW(Fajl::beolvasJegyek(test.c_str(), jegyek));
    } END;
// helytelen filename - jegyekBeolvasasa
    TEST(Throw, JegyekBeolvasasa){
        DinTomb<Jegy> jegyek;
        String test = "random123456789.txt";
        EXPECT_THROW(Fajl::beolvasJegyek(test.c_str(), jegyek), std::runtime_error);
    } END;
// VONATOK - Konstruktorok
// default construktor
    TEST(Default_Construktor, VonatClass){
        Vonat test;
        EXPECT_EQ(0, strcmp(test.get_Vonatszam().c_str(), ""));
        EXPECT_EQ(0, strcmp(test.get_indAll().c_str(), ""));
        EXPECT_EQ(0, strcmp(test.get_erkAll().c_str(), ""));
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
        EXPECT_EQ(0, strcmp(test.get_Vonatszam().c_str(), "vonatszam"));
        EXPECT_EQ(0, strcmp(test.get_indAll().c_str(), "ind_allomas"));
        EXPECT_EQ(0, strcmp(test.get_erkAll().c_str(), "erk_allomas"));
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
        EXPECT_EQ(0, strcmp(test.get_Vonatszam().c_str(), test2.get_Vonatszam().c_str()));
        EXPECT_EQ(0, strcmp(test.get_indAll().c_str(), test2.get_indAll().c_str()));
        EXPECT_EQ(0, strcmp(test.get_erkAll().c_str(), test2.get_erkAll().c_str()));
        EXPECT_TRUE(test.get_indIdo().ora == test2.get_indIdo().ora && test.get_indIdo().perc == test2.get_indIdo().perc);
        EXPECT_TRUE(test.get_erkIdo().ora == test2.get_erkIdo().ora && test.get_erkIdo().perc == test2.get_erkIdo().perc);
        EXPECT_TRUE(test2.getKeses() == test.getKeses());
        EXPECT_TRUE(test2.getKocsiDB() == test.getKocsiDB());
    } END;

// JEGYEK - KONSTRUKTOROK

// default konstruktor
    TEST(Default_Construktor, JegyClass){
        Jegy test;
        EXPECT_EQ(0, strcmp(test.getVsz().c_str(), ""));
        EXPECT_EQ(0, strcmp(test.getIndAll().c_str(), ""));
        EXPECT_EQ(0, strcmp(test.getErkAll().c_str(), ""));
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
        EXPECT_EQ(0, strcmp(test.getVsz().c_str(), "vonatszam"));
        EXPECT_EQ(0, strcmp(test.getIndAll().c_str(), "ind_all"));
        EXPECT_EQ(0, strcmp(test.getErkAll().c_str(), "erk_all"));
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
        EXPECT_NO_THROW(test[0] = 0);
    } END;

    TEST(RosszIDX, DinTomb){
        DinTomb<int> test;
        test.push_back(1);
        EXPECT_THROW(test[2] = 0;, std::out_of_range);
    } END;

// Elem torlese

    TEST(BenneVanTorles, DinTomb){
        DinTomb<int> test;
        test.push_back(1);
        EXPECT_NO_THROW(test.del_element(1));
    } END;

    TEST(NincsBenneTorles, DinTomb){
        DinTomb<int> test;
        test.push_back(1);
        EXPECT_THROW(test.del_element(2), std::runtime_error);
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
        EXPECT_TRUE(output.str().find("Kerem adja meg a vonatszamot!") != std::string::npos);
        EXPECT_TRUE(output.str().find("Honnan?") != std::string::npos);
        EXPECT_TRUE(output.str().find("Hova?") != std::string::npos);
        EXPECT_TRUE(output.str().find("Kerem adja meg az indulas idopontjat (ora perc alakban) !") != std::string::npos);
        EXPECT_TRUE(output.str().find("Kerem adja meg az erkezes idopontjat (ora perc alakban) !") != std::string::npos);
        EXPECT_TRUE(output.str().find("Kerem adja meg kocsik szamat! ") != std::string::npos);
        EXPECT_TRUE(output.str().find("Kerem adja meg hany hely van egy kocsiban!") != std::string::npos);
        EXPECT_TRUE(output.str().find(" vonat sikeresen letrehozva!") != std::string::npos);
        Vonat uj = menu.getVonat(0);
        EXPECT_EQ(0, strcmp(uj.get_Vonatszam().c_str(), "vonatszam"));
        EXPECT_EQ(0, strcmp(uj.get_indAll().c_str(), "ind_allomas"));
        EXPECT_EQ(0, strcmp(uj.get_erkAll().c_str(), "erk_allomas"));
        EXPECT_TRUE(uj.get_indIdo().ora == 12 && uj.get_indIdo().perc == 12);
        EXPECT_TRUE(uj.get_erkIdo().ora == 13 && uj.get_erkIdo().perc == 13);
        EXPECT_EQ(uj.getKocsiDB(), 1);
        EXPECT_EQ(uj.getKocsi(0).get_helyDB(), 10);
    } END;

    TEST(UjVonat.MarLetezik, MenuClass){
        std::istringstream input1(
            "vonatszam\n"
            "ind_allomas\n"
            "erk_allomas\n"
            "12 12\n"
            "13 13\n"
            "1\n"
            "10\n" 
        );
        std::istringstream input2(
            "vonatszam\n"
            "ind_allomas2\n"
            "erk_allomas2\n"
            "10 10\n"
            "11 11\n"
            "1\n"
            "10\n" 
        );
        std::ostringstream output;
        std::streambuf* cinBuf = std::cin.rdbuf();
        std::streambuf* coutBuf = std::cout.rdbuf();
        Menu menu;
        std::cin.rdbuf(input1.rdbuf());
        std::cout.rdbuf(output.rdbuf());
        menu.uj_vonat();
        std::cin.rdbuf(input2.rdbuf());
        menu.uj_vonat();
        std::cin.rdbuf(cinBuf);
        std::cout.rdbuf(coutBuf);
        EXPECT_EQ(menu.getVonatok().getSiz(), 1);
        Vonat uj = menu.getVonat(0);
        EXPECT_EQ(0, strcmp(uj.get_Vonatszam().c_str(), "vonatszam"));
        EXPECT_EQ(0, strcmp(uj.get_indAll().c_str(), "ind_allomas"));
        EXPECT_EQ(0, strcmp(uj.get_erkAll().c_str(), "erk_allomas"));
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
        EXPECT_TRUE(out.str().find("Kerem adja meg a vonat szamat! ") != std::string::npos);
        EXPECT_TRUE(out.str().find("Ha mindent rendben talal, akkor kerem irjon be 1-et, ha nem akkor 0-t!") != std::string::npos);
        EXPECT_TRUE(out.str().find("vonatszam vonat torolve") != std::string::npos);
        EXPECT_EQ(0, menu.getVonatok().getSiz());
    } END;

    TEST(VonatTorleseNemLetezik, MenuClass){
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
            "random\n"
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
        EXPECT_TRUE(out.str().find("Nem talalhato ilyen vonatszam a rendszerben!") != std::string::npos);
        EXPECT_EQ(1, menu.getVonatok().getSiz());
        EXPECT_EQ(0, strcmp(menu.getVonat(0).get_Vonatszam().c_str(), "vonatszam"));
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
            "ind_allomas\n"
            "erk_allomas\n"
            "vonatszam\n"
            "1\n"
            "1\n"
        );
        std::ostringstream jegyOut;
        std::cin.rdbuf(jegyIN.rdbuf());
        std::cout.rdbuf(jegyOut.rdbuf());
        menu.foglalVegallomasok();
        std::cin.rdbuf(eredetiIN);
        std::cout.rdbuf(eredetiOut);
        EXPECT_TRUE(jegyOut.str().find("Honnan?") != std::string::npos);
        EXPECT_TRUE(jegyOut.str().find("Hova?") != std::string::npos);
        EXPECT_TRUE(jegyOut.str().find("Vonatok ind_allomas es erk_allomas kozott:") != std::string::npos);
        EXPECT_TRUE(jegyOut.str().find("Vonatszam: vonatszam") != std::string::npos);
        EXPECT_TRUE(jegyOut.str().find("Kerem adja meg a vonat szamat!") != std::string::npos);
        EXPECT_TRUE(jegyOut.str().find("1 kocsi van a vonaton") != std::string::npos);
        EXPECT_TRUE(jegyOut.str().find("Melyik helyet szeretne foglalni?") != std::string::npos);
        EXPECT_TRUE(jegyOut.str().find("1 hely a 1 kocsiban lefoglalva!") != std::string::npos);
        EXPECT_EQ(menu.getJegyek().getSiz(), 1);
        Jegy jegy = menu.getJegy(0);
        EXPECT_EQ(0, strcmp(jegy.getVsz().c_str(), "vonatszam"));
        EXPECT_EQ(0, strcmp(jegy.getIndAll().c_str(), "ind_allomas"));
        EXPECT_EQ(0, strcmp(jegy.getErkAll().c_str(), "erk_allomas"));
        EXPECT_EQ(1, jegy.getKocsiszam());
        EXPECT_EQ(1, jegy.getHelyszam());
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
        EXPECT_TRUE(kesesOUT.str().find("Kerem adja meg a vonat szamat! ") != std::string::npos);
        EXPECT_TRUE(kesesOUT.str().find("A vonatszam vonat aktualis kesese: 0") != std::string::npos);
        EXPECT_TRUE(kesesOUT.str().find("Kerem adja meg mennyire szeretne a kesest beallitani!") != std::string::npos);
        EXPECT_TRUE(kesesOUT.str().find("A keses atallitva 30 percre") != std::string::npos);
        Vonat vonat = menu.getVonat(0);
        EXPECT_EQ(30, vonat.getKeses());
    } END;

    TEST(SetKesesNemLetezoVonat, MenuClass){
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
            "random\n"
            "30\n"
        );
        std::ostringstream kesesOUT;
        std::cout.rdbuf(kesesOUT.rdbuf());
        std::cin.rdbuf(kesesIN.rdbuf());
        menu.keses_beallit();
        std::cin.rdbuf(eredetiIN);
        std::cout.rdbuf(eredetiOUT);
        EXPECT_TRUE(kesesOUT.str().find("Kerem adja meg a vonat szamat! ") != std::string::npos);
        EXPECT_TRUE(kesesOUT.str().find("Nem talalhato ilyen vonatszam a rendszerben!") != std::string::npos);
        Vonat vonat = menu.getVonat(0);
        EXPECT_EQ(0, vonat.getKeses());
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
        std::streambuf* eredetiCIN = std::cin.rdbuf();
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
        EXPECT_TRUE(keresOUT.str().find("Kerem adja meg a vonat szamat!") != std::string::npos);
        EXPECT_TRUE(keresOUT.str().find("Vonatszam: vonatszam") != std::string::npos);
        EXPECT_TRUE(keresOUT.str().find("Indulasi allomas: ind_allomas") != std::string::npos);
        EXPECT_TRUE(keresOUT.str().find("Erkezesi allomas: erk_allomas") != std::string::npos);
    } END;

    TEST(VonatAdatainakKereseseNemLetezoVonat, MenuClass){
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
        std::streambuf* eredetiCIN = std::cin.rdbuf();
        std::cin.rdbuf(vonatIN.rdbuf());
        menu.uj_vonat();
        std::cin.rdbuf(eredetiCIN);
        std::cout.rdbuf(eredetiCOUT);

        std::istringstream keresIN(
            "random\n"
        );
        std::ostringstream keresOUT;
        std::cin.rdbuf(keresIN.rdbuf());
        std::cout.rdbuf(keresOUT.rdbuf());
        menu.vonatAdatok();
        std::cin.rdbuf(eredetiCIN);
        std::cout.rdbuf(eredetiCOUT);
        EXPECT_TRUE(keresOUT.str().find("Kerem adja meg a vonat szamat!") != std::string::npos);
        EXPECT_TRUE(keresOUT.str().find("Nem talalhato ilyen vonatszam a rendszerben!") != std::string::npos);
        Vonat uj = menu.getVonat(0);
        EXPECT_EQ(0, strcmp(uj.get_Vonatszam().c_str(), "vonatszam"));
        EXPECT_EQ(0, strcmp(uj.get_indAll().c_str(), "ind_allomas"));
        EXPECT_EQ(0, strcmp(uj.get_erkAll().c_str(), "erk_allomas"));
    } END;
}
