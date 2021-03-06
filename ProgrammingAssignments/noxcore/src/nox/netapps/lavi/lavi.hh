/* Copyright 2010 (C) Stanford University.
 *
 * This file is part of NOX.
 *
 * NOX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * NOX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with NOX.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef lavi_HH
#define lavi_HH

#include "component.hh"
#include "config.h"

#ifdef LOG4CXX_ENABLED
#include <boost/format.hpp>
#include "log4cxx/logger.h"
#else
#include "vlog.hh"
#endif

namespace vigil
{
  using namespace std;
  using namespace vigil::container;

  /** \brief lavi: Components that allows network state to be enquired
   * \ingroup noxcomponents
   * 
   * This module is now a dummy module that starts all the relevant
   * components instead.  This is to allow changes of components needed
   * at runtime.
   *
   * This version of LAVI is a partial rewrite from previous version, 
   * using the new components in NOX.
   * 
   * @author ykk
   * @date May 2010
   */
  class lavi
    : public Component 
  {
  public:
    /** \brief Constructor of lavi.
     *
     * @param c context
     * @param node XML configuration (JSON object)
     */
    lavi(const Context* c, const json_object* node)
      : Component(c)
    {}
    
    /** \brief Configure lavi.
     * 
     * Parse the configuration, register event handlers, and
     * resolve any dependencies.
     *
     * @param c configuration
     */
    void configure(const Configuration* c);

    /** \brief Start lavi.
     * 
     * Start the component. For example, if any threads require
     * starting, do it now.
     */
    void install();

    /** \brief Get instance of lavi.
     * @param c context
     * @param component reference to component
     */
    static void getInstance(const container::Context* c, 
			    lavi*& component);

  private:

  };
}

#endif
