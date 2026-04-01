#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	/** Default-constructs a ShrubberyCreationForm (implementation-defined target). */
	ShrubberyCreationForm();

	/** Constructs the form with a target used to name the output file. */
	explicit ShrubberyCreationForm(const std::string &target);

	/** Copy-constructs from another ShrubberyCreationForm. */
	ShrubberyCreationForm(const ShrubberyCreationForm &other);

	/** Copy-assigns from another ShrubberyCreationForm. */
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	/** Virtual destructor. */
	virtual ~ShrubberyCreationForm();

private:
	/**
	 * Performs the concrete action of this form.
	 * Typically writes ASCII trees to a "<target>_shrubbery" file.
	 */
	virtual void executeAction() const;
};

#endif
