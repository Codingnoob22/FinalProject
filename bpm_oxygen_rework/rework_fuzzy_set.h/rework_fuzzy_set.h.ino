void fuzzySet()
{

//FUZZY INPUT BPM
FuzzyInput *detakjantung = new FuzzyInput(1);

detakjantung->addFuzzySet(rileks);
detakjantung->addFuzzySet(calm);
detakjantung->addFuzzySet(anxiety);
detakjantung->addFuzzySet(stress);

fuzzy->addFuzzyInput(detakjantung);

//FUZZY INPUT Oxygen
FuzzyInput *oksigen = new FuzzyInput(2);

oksigen->addFuzzySet(ganyaman);
oksigen->addFuzzySet(cemas);
oksigen->addFuzzySet(tenang);
oksigen->addFuzzySet(santai);

fuzzy->addFuzzyInput(oksigen);

//FUZZY INPUT GSR
FuzzyInput *handresistant = new FuzzyInput(3);

handresistant->addFuzzySet(relax);
handresistant->addFuzzySet(chill);
handresistant->addFuzzySet(worry);
handresistant->addFuzzySet(nervous);

fuzzy->addFuzzyInput(handresistant);

//FUZZY INPUT GSR
FuzzyInput *hasil = new FuzzyOutput(1);

hasil->addFuzzySet(r);
hasil->addFuzzySet(c);
hasil->addFuzzySet(a);
hasil->addFuzzySet(s);

fuzzy->addFuzzyOutput(hasil);
}
