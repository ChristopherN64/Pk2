#ifndef MEDIUM_H
#define MEDIUM_H

#include <string>

    class Medium{
        private:
            static int iObjectCount;
            const int id;
            std::string titel;
            int jahr;
            
        public:
            Medium(std::string tlt, int j);
            virtual ~Medium();
            int alter();
            virtual void druckeDaten();

            //Getter
            inline int getId();
            inline int getJahr();
            inline std::string getTitel();
    };


    class Audio : public Medium
    {
        private:
            std::string interpret;
            int dauer;

        public:
            Audio(std::string t,int j, std::string i, int d);
            void druckeDaten() override;
    };


    class Bild : public Medium
    {
        private:
            std::string ort;

        public:
            Bild(std::string t,int j,std::string o);
            void druckeDaten() override;
    };


#endif