FROM gcc:latest

#Nastavi delovno mapo
WORKDIR /app

#Kopiramo vse datoteke v app
COPY . /app

#Namesti potrebne pakete
RUN apt-get update && apt-get install -y g++ make

#Sestavi aplikacijo dn1
RUN g++ -o dn1 dn1.cpp

#Definira ukaz za zagon
CMD ["./dn1"]
