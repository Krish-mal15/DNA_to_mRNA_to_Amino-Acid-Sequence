#include <iostream>
#include <map>
#include <string>

// Use Visual Studio Community 2022 amd_64 and x86 compiler

using namespace std;

string getRNASequence(string &dna){
   
   for (char &i : dna){

       char replacement = i;
       
       if (i == 'A'){
            replacement = 'U';
       }
       if (i == 'C'){
            replacement = 'G';
       }  
       if (i == 'G'){
            replacement = 'C';
       }  
       if (i == 'T'){
            replacement = 'A';
    }
    i = replacement;
   }
    return dna;
}

string getAminoAcid(const string& codon) {
    // Define the mapping of codons to amino acid full names
    // Used ChatGPT to generate dictionary that can convert DNA codons to Amino acids.
    // If using mRNA, use the function that converts the DNA to mRNA and then use a predifined dictionary
    map<string, string> codonToAmino = {
        {"TTT", "Phenylalanine"}, {"TTC", "Phenylalanine"}, {"TTA", "Leucine"}, {"TTG", "Leucine"},
        {"CTT", "Leucine"}, {"CTC", "Leucine"}, {"CTA", "Leucine"}, {"CTG", "Leucine"},
        {"ATT", "Isoleucine"}, {"ATC", "Isoleucine"}, {"ATA", "Isoleucine"}, {"ATG", "Methionine"},
        {"GTT", "Valine"}, {"GTC", "Valine"}, {"GTA", "Valine"}, {"GTG", "Valine"},
        {"TCT", "Serine"}, {"TCC", "Serine"}, {"TCA", "Serine"}, {"TCG", "Serine"},
        {"CCT", "Proline"}, {"CCC", "Proline"}, {"CCA", "Proline"}, {"CCG", "Proline"},
        {"ACT", "Threonine"}, {"ACC", "Threonine"}, {"ACA", "Threonine"}, {"ACG", "Threonine"},
        {"GCT", "Alanine"}, {"GCC", "Alanine"}, {"GCA", "Alanine"}, {"GCG", "Alanine"},
        {"TAT", "Tyrosine"}, {"TAC", "Tyrosine"}, {"TAA", "Stop"}, {"TAG", "Stop"},
        {"CAT", "Histidine"}, {"CAC", "Histidine"}, {"CAA", "Glutamine"}, {"CAG", "Glutamine"},
        {"AAT", "Asparagine"}, {"AAC", "Asparagine"}, {"AAA", "Lysine"}, {"AAG", "Lysine"},
        {"GAT", "Aspartic-Acid"}, {"GAC", "Aspartic-Acid"}, {"GAA", "Glutamic-Acid"}, {"GAG", "Glutamic-Acid"},
        {"TGT", "Cysteine"}, {"TGC", "Cysteine"}, {"TGA", "Stop"}, {"TGG", "Tryptophan"},
        {"CGT", "Arginine"}, {"CGC", "Arginine"}, {"CGA", "Arginine"}, {"CGG", "Arginine"},
        {"AGT", "Serine"}, {"AGC", "Serine"}, {"AGA", "Arginine"}, {"AGG", "Arginine"},
        {"GGT", "Glycine"}, {"GGC", "Glycine"}, {"GGA", "Glycine"}, {"GGG", "Glycine"}
    };

    auto it = codonToAmino.find(codon);
    if (it != codonToAmino.end()) {
        return it->second;
    } else {
    
        return "Unknown";
    }
}

int main(){

    string dna;
    cout << "Enter DNA Sequence: ";
    cin >> dna;

    if (dna.length() % 3 != 0){
        cout << "Invalid sequence";
    }

    string codon;
    string aminoSequence;

    for (size_t i = 0; i < dna.length(); i += 3){
        codon = dna.substr(i, 3);
        string amino = getAminoAcid(codon);
        aminoSequence += amino + " ";
    }

    cout << "Amino Acid Sequence: " << aminoSequence << "\n";
    
    string mRNA = getRNASequence(dna);
    cout << "mRNA Sequence: " << mRNA << "\n";

}