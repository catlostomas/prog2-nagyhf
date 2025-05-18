#include "fajlKezeles.hpp"

void Fajl::beolvasVonatok(const std::string& filename, DinTomb<Vonat>& vonatok){
    std::ifstream in(filename);
    if (!in){
        throw std::runtime_error("Nem talalhato a vonatok.txt fajl, kerem hozza letre!");
    }
    vonatok.clear();
    size_t vonatDB;
    in >> vonatDB;
    in.ignore();
    for (size_t i = 0; i < vonatDB; i++){
        std::string tempVsz, tempIndAll, tempErkAll;
        int tempIndOra, tempIndPerc, tempErkOra, tempErkPerc;
        int tempKeses;
        size_t tempKocsiDB;
        in >> tempVsz >> tempIndAll >> tempErkAll >> tempIndOra >> tempIndPerc >> tempErkOra >> tempErkPerc >> tempKeses >> tempKocsiDB;
        in.ignore();
        String vonatszam(tempVsz.c_str());
        String indAll(tempIndAll.c_str());
        String erkAll(tempErkAll.c_str());
        Ido indIdo(tempIndOra, tempIndPerc);
        Ido erkIdo(tempErkOra, tempErkPerc);
        Vonat uj_vonat(vonatszam, indAll, erkAll, indIdo, erkIdo, tempKeses, tempKocsiDB);
        for (size_t j = 0; j < tempKocsiDB; j++){
            size_t helyDB, foglaltszam;
            in >> helyDB >> foglaltszam;
            in.ignore();
            Kocsi k(j, helyDB);
            for (size_t x = 0; x < foglaltszam; x++){
                int foglaltID;
                in >> foglaltID;
                k.foglal_hely(foglaltID);
            }
            in.ignore();
            uj_vonat.getKocsi(j) = k;
        }
        vonatok.push_back(uj_vonat);
    }
    in.close();
}

void Fajl::beolvasJegyek(const std::string& filename, DinTomb<Jegy>& jegyek){
    std::ifstream in(filename);
    if (!in){
        throw std::runtime_error("Nem talalhato a jegyek.txt fajl, kerem hozza letre!");
    }
    size_t jegyDB;
    in >> jegyDB;
    in.ignore();
    for (size_t i = 0; i < jegyDB; i++){
        std::string tempIndAll, tempErkAll, tempVsz;
        int tempIndOra, tempIndPerc, tempErkOra, tempErkPerc;
        int tempKocsiszam, tempHelyszam, tempJegyID;
        std::getline(in, tempIndAll);
        std::getline(in, tempErkAll);
        in >> tempIndOra >> tempIndPerc;
        in >> tempErkOra >> tempErkPerc;
        std::getline(in, tempVsz);
        if (tempVsz.empty()){
            std::getline(in, tempVsz);
        }
        in >> tempKocsiszam >> tempHelyszam >> tempJegyID;
        in.ignore();
        String indAll(tempIndAll.c_str());
        String erkAll(tempErkAll.c_str());
        String vonatszam(tempVsz.c_str());
        Ido ind(tempIndOra, tempIndPerc);
        Ido erk(tempErkOra, tempErkPerc);

        Jegy uj_jegy(indAll, erkAll, ind, erk, vonatszam, tempKocsiszam, tempHelyszam, tempJegyID);
        jegyek.push_back(uj_jegy);
    }
    in.close();
}

void Fajl::mentesVonatok(const std::string& filename, const DinTomb<Vonat>& vonatok){
    std::ofstream out(filename);
    if (!out){
        throw std::runtime_error("Nem talalhato a vonatok.txt fajl, kerem hozza letre!");
    }
    out << vonatok.getSiz() << "\n";
    for (size_t i = 0; i < vonatok.getSiz(); i++){
        const Vonat& v = vonatok[i];
        out << v.get_Vonatszam().c_str() << " " << v.get_indAll().c_str() << " " << v.get_erkAll().c_str() << " " << v.get_indIdo().ora << " " << v.get_indIdo().perc << " " << v.get_erkIdo().ora << " " << v.get_erkIdo().perc << " " << v.getKeses() << " " << v.getKocsiDB() << "\n";
        for (size_t j = 0; j < v.getKocsiDB(); j++){
            const Kocsi& k = v.getKocsi(j);
            size_t foglalt = 0;
            for (int x = 0; x < k.get_helyDB(); x++){
                if (k.get_hely(x).getFoglalt()){
                    foglalt++;
                }
            }
            out << k.get_helyDB() << " " << foglalt << "\n";
            for (int x = 0; x < k.get_helyDB(); x++){
                const Hely& h = k.get_hely(x);
                if (h.getFoglalt()){
                    out << h.getID() << " ";
                }
            }
            out << "\n";
        }
    }
    out.close();
}

void Fajl::mentesJegyek(const std::string& filename, const DinTomb<Jegy>& jegyek){
    std::ofstream out(filename);
    if (!out){
        throw std::runtime_error("Nem talalhato a jegyek.txt fajl, kerem hozza letre!");
    }
    out << jegyek.getSiz() << "\n";
    for (size_t i = 0; i < jegyek.getSiz(); i++){
        const Jegy& j = jegyek[i];
        out << j.getIndAll().c_str() << "\n";
        out << j.getErkAll().c_str() << "\n";
        out << j.getIndIdo().ora << ' ' << j.getIndIdo().perc << "\n";
        out << j.getErkIdo().ora << ' ' << j.getErkIdo().perc << "\n";
        out << j.getVsz().c_str() << "\n";
        out << j.getKocsiszam() << ' ' << j.getHelyszam() << ' ' << j.getJegyID() << "\n";
    }
    out.close();
}

