#ifndef TOOLKIT_COMMON_VERSION_HPP
#define TOOLKIT_COMMON_VERSION_HPP
#include <string>

#include "Error.hpp"
#include "Object.hpp"

namespace octetos
{
namespace toolkit
{

	/**
	 * \brief Informacion de Version
	 * \details Acerda de 'Semantica de Versionado' https://semver.org/lang/es/.
	 **/
	class Version: public Object
	{
	public:	
		class InvalidComparison : public Error
		{
		public:
			InvalidComparison(const std::string& msg ,std::string filename,int lineNumber);
			InvalidComparison(const std::string& msg);
		};
		
		/**
		* \brief Representa la fase del proyecto.
		* \details Tipicamente un proyecto o sprint comienz en la vervion X-alpha, luego pasa a X-beta y finalmente se genera X-release, lo que sigue a continuacion del guion es la fase aqui representado
		**/
		enum Stage
		{
			unknown,
			snapshot,  
			prealpha,
			alpha,
			beta,
			betarelease,
			rc,
			prerelease,
			release,
			ga,
			rtm	
		};
		
		/**
		* \brief Paramaetro pasado a la funcion toString para determinar el formato de texto geneerado
		* */
		enum Format
		{
			FULL,
			ONLY_NUMBERS
		};
		
	private:	
		/**
		* \brief Número major
		* */
		short major;
		/**
		* \brief Número menor
		* */
		short minor;
		/**
		* \brief Número patch
		* */
		short patch;
		/**
		* \brief Build del projecto(solose acepta un numero intero largo)
		* */
		unsigned long build;
		/**
		* \brief Fase del proyecto
		* */
		Stage stage;
		/**
		* \brief Nombre de la version
		* */
		std::string name;                

	public:
		/**
		* \brief Limpia todos los datos
		* */
		void init();
		/**
		* \brief Retorna el numero major.
		* */
		short getMajor() const;
		/**
		* \brief Retorna el número menor
		* */
		short getMinor() const;
                /**
                 * \brief Retorna el número patch
                 * */
		short getPatch() const;
                /**
                 * \brief Retorna build
                 * */
		unsigned long getBuild() const;
                /**
                 * \brief Retorna el estado
                 * */
		Stage getStage() const;
                /**
                 * \brief Retorna el nombre de la version
                 * */
                const std::string& getName() const;
                /**
                 * \brief Determina el orden relativo entre dos obejtos Version
                 * \return true si el objeto pasado como parametro es amyor o igual, false en otro caso
                 * */
                bool operator >=(const Version& v);
                /**
                 * \brief Determina el orden relativo entre dos obejtos Version
                 * \return true si el objeto pasado como parametro es menor, false en otro caso
                 * */
                bool operator <(const Version& v);
                /**
                 * \brief Hace una copia del objecto version.
                 * */
                const Version& operator =(const Version& v);
                
                /**
                 * \brief Simple mente limpa las variables intenas
                 * */
		Version();
                /**
                 * \brief Asigna numero major y menor. A patch se asigna a 0, los restantas datos son limpiados.
                 * */
                Version(short major,short minor);
                /**
                 * \brief Asigna numero major, menor y patch, los restantas datos son limpiados
                 * */
                Version(short major,short minor,short patch);
                /**
                 * \brief Asigna todos los campos de version.
                 * */
                void set(short major,short minor,short patch,Stage stage,unsigned long build, const std::string& name);
                /**
                 * \brief Asigna numero major, menor y patch.
                 * */
                void setNumbers(short major,short minor,short patch);
                /**
                 * \brief Asigna numero major y menor. A patch se le asigna 0.
                 * */
                void setNumbers(short major,short minor);
                /**
                 * \brief Asigna solamanete el valor major. A menor y patch se le asigna 0.
                 * */
                void setNumbers(short major);
                /**
                 * \brief Asigna la etapa del proyecto
                 * */
                void setStage(Stage stage);
                /**
                 * \brief Asigna el build de la version
                 * \details Solo se acepta un entero largo positivo. por lo que no se aceptan metadatos en el sentido convencional, tampoco tiene signifacod alguno el compracion o validaciones por lo que es libre ade asignar el valor que desea
                 * */
                void setBuild(unsigned long build);
                /**
                 * Asigna el nombre de la version
                 * */
                void setName(const std::string& name);
                /**
                 * \brief Retorna una representa en texto de la version.
                 * \param formato Determina el formato generado.
                 * */
		std::string toString(Format formato = Format::FULL) const; 
                /**
                 * \brief Asinga los valores con datos leidos desde un archivo
                 * \param filename nombre del archivo
                 * */
                bool fromFile(const std::string& filename);       
                /**
                 * \brief Asinga los valores con datos leidos desde ana cadena de texto
                 * \param str Texto a leer.
                 * */                 
                bool fromString(const std::string& str); 
                
                static bool valid(const std::string& str);
	};
	
}
}
#endif
