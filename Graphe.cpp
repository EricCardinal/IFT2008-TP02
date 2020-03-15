/**
* \file Graphe.cpp
* \brief Implémentation d'un graphe orienté.
* \author Étudiant(e)
* \version 0.1
* \date mars 2020
*
*  Travail pratique numéro 2
*
*/

#include "Graphe.h"

//vous pouvez inclure d'autres librairies si c'est nécessaire

namespace TP2
{

	//Mettez l'implémentation de vos méthodes ici.
		// Constructeur
	Graphe::Graphe(size_t nbSommets):
			m_nbSommets(nbSommets), m_nbArcs(0)
	{
		this->resize(m_nbSommets);
	}

	// Destructeur
	Graphe::~Graphe()
	{
		//TODO Constuire le destructeur... Vider Vectors
	}

	// Change la taille du graphe en utilisant un nombre de sommet = nouvelleTaille
	// Vous pouvez supposer que cette méthode va être appliquée uniquement sur un graphe vide.
	void Graphe::resize(size_t nouvelleTaille)
	{
		m_nbSommets = nouvelleTaille;
		m_sommets.clear();
		for(size_t iter = 0; iter < m_nbSommets; iter++)
		{
			m_sommets.push_back("");
			m_listesAdj.push_back({});
		}
	}

	// Donne un nom à un sommet en utlisant son numéro (indice dans le vector).
	// Exception logic_error si sommet supérieur à nbSommets
	void Graphe::nommer(size_t sommet, const std::string& nom)
	{
		if(sommet > m_nbSommets)
		{
			throw std::logic_error("<Graphe::nommer> Numero de sommet supperieur au nombre de sommet");
		}
		else
		{
			m_sommets[sommet] = nom;
		}
	}

	// Ajoute un arc au graphe
	// Exception logic_error si source ou destination supérieur à nbSommets
	// Exception logic_error si l'arc existe déjà dans le graphe
	void Graphe::ajouterArc(size_t source, size_t destination, float duree, float cout, int ns)
	{
		if(source >= m_nbSommets || destination >= m_nbSommets)
		{
			throw std::logic_error("<Graphe::ajouterArc> La source ou la destination est illegale");
		}
		m_nbArcs++;
		Ponderations p(duree, cout, ns);
		Arc nouvelArc (destination, p);
		std::cout << "\nAll Hell Break Loose\n";
		m_listesAdj[source].push_back(nouvelArc);
		std::cout << "\nI am OK\n";


	}

	// Supprime un arc du graphe
	// Exception logic_error si source ou destination supérieur à nbSommets
	// Exception logic_error si l'arc n'existe pas dans le graphe
	void Graphe::enleverArc(size_t source, size_t destination)
	{

	}

	// Vérifie si un arc existe
	// Exception logic_error si source ou destination supérieur à nbSommets
	bool Graphe::arcExiste(size_t source, size_t destination) const
	{

		//TODO - Update
		return true;
	}

	// Retourne la liste de successeurs d'un sommmet
	// Exception logic_error si sommet supérieur à nbSommets
	std::vector<size_t> Graphe::listerSommetsAdjacents(size_t sommet) const
	{


	}

	// Retourne le nom d'un sommet
	// Exception logic_error si sommet supérieur à nbSommets
	std::string Graphe::getNomSommet(size_t sommet) const
	{

		//TODO
		return "ABC";
	}

	// Retourne le numéro d'un sommet
	// Exception logic_error si nom n'existe pas dans le graphe
	size_t Graphe::getNumeroSommet(const std::string& nom) const
	{
		size_t i = 0;
		while((size_t)i < m_nbSommets)
		{
			if(m_sommets[i] == nom)
			{
				return i;
			}
			i++;
		}
		throw std::logic_error("<Graphe::getNumeroSommet> Nom de ville inconnu.");

	}

	// Retourne le nombre de sommet du graphe
	int Graphe::getNombreSommets() const
	{
		return m_nbSommets;
	}

	// Retourne le nombre des arcs du graphe
	int Graphe::getNombreArcs() const
	{
		return m_nbArcs;
	}

	// Retourne les pondérations se trouvant dans un arc (source -> destination)
	// Exception logic_error si source ou destination supérieur à m_nbSommets
	Ponderations Graphe::getPonderationsArc(size_t source, size_t destination) const
	{

	}

}//Fin du namespace
