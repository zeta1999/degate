/* -*-c++-*-

 This file is part of the IC reverse engineering tool degate.

 Copyright 2008, 2009, 2010 by Martin Schobert

 Degate is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 any later version.

 Degate is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with degate. If not, see <http://www.gnu.org/licenses/>.

 */

#ifndef __DOTATTRIBUTES_H__
#define __DOTATTRIBUTES_H__

#include "globals.h"

#include <string>
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace degate {

  /**
   * Helper class to handle attributes for the dot language.
   *
   */
  class DOTAttributes {
  private:

    std::vector<std::pair<std::string, std::string> > attributes;

  public:

    /**
     * The constructor.
     */
    DOTAttributes() {};

    /**
     * The destructor, that destroys a DOTAttributes object.
     */
    ~DOTAttributes() {};

    /**
     * Add a key/value attribute.
     *
     * If this method is called multiple times with the same
     * attribute name, the last value is accepted.
     *
     * The value string should not contain quotation marks. If it
     * has one, you should handle the escaping by yourself.
     *
     * @param attribute_name The attribute name as a string.
     * @param value The string value. You don't have to add opening and closing quotation marks.
     */

    void add(std::string const& attribute_name, std::string const& value);

    /**
     * Get the attributes as a string.
     *
     * @return Returns the dot attributes as a string, you can directly write into the dot file.
     *        The string is of format [color="red",label="N3018",shape="box"], including the
     *        squared brackets.
     */

    std::string get_string() const;

  };

}

#endif
