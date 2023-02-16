//
// Created by liu on 23-2-15.
//

#include <boost/python.hpp>
#include <boost/python/numpy.hpp>

#include "../src/ELSED.h"

namespace np = boost::python::numpy;
namespace py = boost::python;

py::list detect_line_use_elsed(np::ndarray img) {
  py::list lines;
  upm::ELSED elsed;

  cv::Mat curr_img(img.shape(0), img.shape(1), CV_8UC3, img.get_data());
  upm::Segments segs = elsed.detect(curr_img);

  for (int i = 0; i < segs.size(); i++) {
    py::list one_seg;
    one_seg.append(segs[i][0]);
    one_seg.append(segs[i][1]);
    one_seg.append(segs[i][2]);
    one_seg.append(segs[i][3]);

    lines.append(one_seg);
  }

  return lines;
}

BOOST_PYTHON_MODULE (pyelsed) {
  using namespace boost::python;
  np::initialize();
  def("detect_line_use_elsed", detect_line_use_elsed);
}


