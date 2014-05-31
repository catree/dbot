/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2014 Max-Planck-Institute for Intelligent Systems,
 *                     University of Southern California
 *    Manuel Wuthrich (manuel.wuthrich@gmail.com)
 *    Jan Issac (jan.issac@gmail.com)
 *
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * @date 05/25/2014
 * @author Manuel Wuthrich (manuel.wuthrich@gmail.com)
 * @author Jan Issac (jan.issac@gmail.com)
 * Max-Planck-Institute for Intelligent Systems, University of Southern California
 */


#ifndef STATE_FILTERING_DISTRIBUTION_FEATURES_EVALUABLE_HPP
#define STATE_FILTERING_DISTRIBUTION_FEATURES_EVALUABLE_HPP

#include <cmath>
#include <state_filtering/distribution/features/unnormalized_evaluable.hpp>

namespace filter
{

template <typename ScalarType_, int SIZE>
class Evaluable:
        public UnnormalizedEvaluable<ScalarType_, SIZE>
{
public:
    typedef UnnormalizedEvaluable<ScalarType_, SIZE>    BaseType;
    typedef typename BaseType::ScalarType               ScalarType;
    typedef typename BaseType::VariableType             VariableType;

    /**
     * @brief Returns the probability of the given sample
     *
     * @param sample    Probability sample
     *
     * @return Probability of the sample
     */
    virtual ScalarType probability(const VariableType& sample) const
    {
        return std::exp(logProbability(sample));
    }

    /**
     * @brief Returns the probability log of the given sample
     *
     * @param sample    Probability sample
     *
     * @return Log of sample probability
     */
    virtual ScalarType logProbability(const VariableType& sample) const = 0;

    /**
     * @brief Returns the probability log of the given sample
     *
     * @param sample    Probability sample
     *
     * @return Log of sample probability
     */
    virtual ScalarType logUnnormalizedProbability(const VariableType& sample) const
    {
        return logProbability(sample);
    }
};

}

#endif
