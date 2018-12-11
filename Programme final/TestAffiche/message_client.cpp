/** \file message_client.cpp
 * \brief Fichier d'implémentation de la classe MessageClient.
 * \author Sébastien Angibaud
 */

#include "message_client.h"

#include <QStringList>

/** --------------------------------------------------------------------------------------
 * \brief Constructeur par défaut de la classe MessageClient.
 */
MessageClient::MessageClient()
    : m_numero(0), m_valide(false)
{

}

/** --------------------------------------------------------------------------------------
 * \brief Constructeur de la classe MessageClient.
 * \param texte Une référence constante sur le texte reçu ou à envoyer.
 */
MessageClient::MessageClient(const QString & texte)
{
    m_valide = true;

    QStringList liste = texte.split('|');
    if ( liste.size() < 2 || liste.size() > 3 )
        m_valide = false;
    else
    {
        QStringList::Iterator it = liste.begin();

        // le numero
        m_numero = it->toInt( & m_valide );
        ++it;

        // l'ordre
        m_ordre = *it;        ++it;

        // eventuellement le parametre
        for ( ; it != liste.end(); ++it )
            m_parametres.push_back( *it );
    }
}

/** --------------------------------------------------------------------------------------
 * \brief Constructeur de la classe MessageClient.
 * \param numero Le numero du message.
 * \param ordre L'ordre du message.
 */
MessageClient::MessageClient(int numero, QString ordre)
    : m_numero(0), m_ordre(ordre), m_valide(true)
{

}

/** --------------------------------------------------------------------------------------
 * \brief Constructeur de la classe MessageClient.
 * \param numero Le numero du message.
 * \param ordre L'ordre du message.
 * \param parametres Les parametres du message.
 */
MessageClient::MessageClient(int numero, QString ordre, const std::vector<QString>& parametres)
    : m_numero(numero), m_ordre(ordre), m_parametres(parametres), m_valide(false)
{

}

/** --------------------------------------------------------------------------------------
 * \brief Accesseur du texte.
 * \return Le texte du message.
 */
QString MessageClient::texte() const
{
    QString result( QString::number(m_numero) + "|" + m_ordre );

    for( std::vector<QString>::const_iterator it = m_parametres.begin();
         it != m_parametres.end(); ++it )
        result = result + *it;

    return result;
}

/** --------------------------------------------------------------------------------------
 * \brief Accesseur du numero.
 * \return Le numero du message.
 */
int MessageClient::numero() const
{
    return m_numero;
}

/** --------------------------------------------------------------------------------------
 * \brief Accesseur de l'ordre du message.
 * \return L'ordre du message.
 */
QString MessageClient::ordre() const
{
    return m_ordre;
}

/** --------------------------------------------------------------------------------------
 * \brief Accesseur du parametre du message.
 * \param pos Le parametre voulu.
 * \return Le parametre du message.
 */
QString MessageClient::parametre( int pos ) const
{
    if ( pos >= 0 && pos < m_parametres.size() )
        return m_parametres[pos];
    else
        return "";
}

/** --------------------------------------------------------------------------------------
 * \brief Indique si le message est valide.
 * \return La validité du message.
 */
bool MessageClient::valide() const
{
    return m_valide;
}

/** --------------------------------------------------------------------------------------
 * \brief Indique si le message a un parametre.
 * \return Un booléen indiquant si le message a un parametre.
 */
bool MessageClient::a_parametre() const
{
    return ! m_parametres.empty();
}

/** --------------------------------------------------------------------------------------
 * \brief Indique le nombre de parametres du message.
 * \return Le nombre de paramètres du message.
 */
int MessageClient::nb_parametres() const
{
    return m_parametres.size();
}

/** --------------------------------------------------------------------------------------
 * \brief Inintialise un paramètre du message.
 * \param pos La position du paramètre à initialiser.
 * \param value La nouvelle valeur du paramètre.
 */
void MessageClient::setParametre(int pos, const QString & value)
{
    if ( pos >= 0 && pos < m_parametres.size() )
       m_parametres[pos] = value;
}
