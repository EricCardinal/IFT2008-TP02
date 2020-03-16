/**
 * \file ReseauAerien.cpp
 * \brief Implémentattion de la classe ReseauAerien.
 * \author Étudiant(e)
 * \version 0.1
 * \date mars 2020
 *
 *  Travail pratique numéro 2
 *
 */

#include "ReseauAerien.h"
#include <sstream>
#include <fstream>
//vous pouvez inclure d'autres librairies si c'est nécessaire

namespace TP2
{

// Méthode fournie
/**
 * \fn void ReseauAerien::chargerReseau(std::ifstream & fichierEntree)
 * \param[in] le fichier contenant l'information sur le réseau
 */
    void ReseauAerien::chargerReseau(std::ifstream & fichierEntree)
    {
        if (!fichierEntree.is_open())
            throw std::logic_error("ReseauAerien::chargerReseau: Le fichier n'est pas ouvert !");

        std::string buff;
        getline(fichierEntree, m_nomReseau);
        m_nomReseau.erase(0, 15);

        int nbVilles;

        fichierEntree >> nbVilles;
        getline(fichierEntree, buff); //villes

        m_unReseau.resize(nbVilles);

        getline(fichierEntree, buff); //Liste des villes

        size_t i = 0;

        getline(fichierEntree, buff); //Premiere ville

        while(buff != "Liste des trajets:")
        {
            std::string ville = buff;

            m_unReseau.nommer(i, ville);

            getline(fichierEntree, buff);
            i++;
        }

        while(!fichierEntree.eof())
        {
            getline(fichierEntree, buff);
            std::string source = buff;

            getline(fichierEntree, buff);
            std::string destination = buff;

            getline(fichierEntree, buff);
            std::istringstream iss(buff);

            float duree;
            iss >> duree;

            float cout;
            iss >> cout;

            int ns;
            iss >> ns;

            m_unReseau.ajouterArc(m_unReseau.getNumeroSommet(source), m_unReseau.getNumeroSommet(destination), duree, cout, ns);
        }
    }

    //À compléter par l'implémentation des autres méthodes demandées

    // Constructeur
    ReseauAerien::ReseauAerien(std::string nomReseau, size_t nbVilles):
    		m_nomReseau(nomReseau)
    {
    	Graphe m_unReseau(nbVilles);
    }

    // Destructeur
    ReseauAerien::~ReseauAerien()
    {
    	//TODO
    }

    // Change la taille du réseau en utilisant un nombre de villes = nouvelleTaille
    void ReseauAerien::resize(size_t nouvelleTaille)
    {
    	m_unReseau.resize(nouvelleTaille);
    }

    // Retourne le plus court chemin selon l'algorithme de Dijkstra
    // origine et destination font partie du graphe
    // Exception std::logic_error si origine et/ou destination absent du réseau
    Chemin ReseauAerien::rechercheCheminDijkstra(const std::string& origine, const std::string& destination, bool dureeCout) const
    {
    	// true - duree
    	// false - cout
    	std::vector<size_t> sommetsSolutionnes;
    	std::vector<size_t> sommetPrecedent;
    	std::queue<size_t> sommetsAttente;
    	std::vector<float> cout;

    	// poid et preceden de la source
    	cout.push_back(0.0);
    	sommetPrecedent.push_back(0);
    	// Ajouter la source a la file
    	size_t unSommet = m_unReseau.getNumeroSommet(origine);
    	float unCout;
    	sommetsAttente.push(unSommet);
    	while(!sommetsAttente.empty())
    	{
    		for(auto iter = m_unReseau.m_listesAdj[unSommet].begin(); iter != m_unReseau.m_listesAdj[unSommet].end(); iter++)
    		{
    			if(dureeCout)
    			{
    				unCout = m_unReseau.getPonderationsArc(m_unReseau.getNumeroSommet(origine), m_unReseau.getNumeroSommet(destination)).duree;
    			}
    			else
    			{
    				unCout = m_unReseau.getPonderationsArc(m_unReseau.getNumeroSommet(origine), m_unReseau.getNumeroSommet(destination)).cout;
    			}
    			cout.push_back(unCout);
    		}
    		sommetsAttente.pop();
    	}







    }

    // Retourne le plus court chemin selon l'algorithme Bellman-Ford
    // origine et destination font partie du graphe
    // 1 <= dureeCoutNiveau <= 3
    // Exception std::logic_error si dureeCoutNiveau hors limite
    // Exception std::logic_error si origine et/ou destination absent du réseau
    Chemin ReseauAerien::rechercheCheminBellManFord(const std::string& origine, const std::string& destination, int dureeCoutNiveau) const
    {

    }


}//Fin du namespace
