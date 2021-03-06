/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hpp>

#include <XmlLDrivers_DocumentStorageDriver.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_Handle.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <CDM_MessageDriver.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Element.hxx>
#include <Standard_Type.hxx>
#include <XmlDrivers_DocumentStorageDriver.hxx>
#include <XmlLDrivers_DocumentRetrievalDriver.hxx>
#include <XmlMDF_ADriver.hxx>
#include <XmlDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Transient.hxx>
#include <Standard_GUID.hxx>
#include <TDocStd_Application.hxx>
#include <XmlDrivers.hxx>

PYBIND11_MODULE(XmlDrivers, mod) {

	// IMPORT
	py::module::import("OCCT.XmlLDrivers");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.XmlMDF");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.XmlObjMgt");
	py::module::import("OCCT.TDocStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlDrivers_DocumentStorageDriver.hxx
	py::class_<XmlDrivers_DocumentStorageDriver, opencascade::handle<XmlDrivers_DocumentStorageDriver>, XmlLDrivers_DocumentStorageDriver> cls_XmlDrivers_DocumentStorageDriver(mod, "XmlDrivers_DocumentStorageDriver", "None");
	cls_XmlDrivers_DocumentStorageDriver.def(py::init<const TCollection_ExtendedString &>(), py::arg("theCopyright"));
	cls_XmlDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &XmlDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_XmlDrivers_DocumentStorageDriver.def("WriteShapeSection", (Standard_Boolean (XmlDrivers_DocumentStorageDriver::*)(XmlObjMgt_Element &)) &XmlDrivers_DocumentStorageDriver::WriteShapeSection, "None", py::arg("thePDoc"));
	cls_XmlDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &XmlDrivers_DocumentStorageDriver::get_type_name, "None");
	cls_XmlDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlDrivers_DocumentStorageDriver::get_type_descriptor, "None");
	cls_XmlDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlDrivers_DocumentStorageDriver::*)() const ) &XmlDrivers_DocumentStorageDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlDrivers_DocumentRetrievalDriver.hxx
	py::class_<XmlDrivers_DocumentRetrievalDriver, opencascade::handle<XmlDrivers_DocumentRetrievalDriver>, XmlLDrivers_DocumentRetrievalDriver> cls_XmlDrivers_DocumentRetrievalDriver(mod, "XmlDrivers_DocumentRetrievalDriver", "None");
	cls_XmlDrivers_DocumentRetrievalDriver.def(py::init<>());
	cls_XmlDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &XmlDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_XmlDrivers_DocumentRetrievalDriver.def("ReadShapeSection", (opencascade::handle<XmlMDF_ADriver> (XmlDrivers_DocumentRetrievalDriver::*)(const XmlObjMgt_Element &, const opencascade::handle<CDM_MessageDriver> &)) &XmlDrivers_DocumentRetrievalDriver::ReadShapeSection, "None", py::arg("thePDoc"), py::arg("theMsgDriver"));
	cls_XmlDrivers_DocumentRetrievalDriver.def("ShapeSetCleaning", (void (XmlDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<XmlMDF_ADriver> &)) &XmlDrivers_DocumentRetrievalDriver::ShapeSetCleaning, "None", py::arg("theDriver"));
	cls_XmlDrivers_DocumentRetrievalDriver.def("PropagateDocumentVersion", (void (XmlDrivers_DocumentRetrievalDriver::*)(const Standard_Integer)) &XmlDrivers_DocumentRetrievalDriver::PropagateDocumentVersion, "None", py::arg("theDocVersion"));
	cls_XmlDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &XmlDrivers_DocumentRetrievalDriver::get_type_name, "None");
	cls_XmlDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
	cls_XmlDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlDrivers_DocumentRetrievalDriver::*)() const ) &XmlDrivers_DocumentRetrievalDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlDrivers.hxx
	py::class_<XmlDrivers, std::unique_ptr<XmlDrivers, Deleter<XmlDrivers>>> cls_XmlDrivers(mod, "XmlDrivers", "None");
	cls_XmlDrivers.def(py::init<>());
	cls_XmlDrivers.def_static("Factory_", (const opencascade::handle<Standard_Transient> & (*)(const Standard_GUID &)) &XmlDrivers::Factory, "None", py::arg("theGUID"));
	cls_XmlDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &XmlDrivers::DefineFormat, "Defines format 'XmlOcaf' and registers its read and write drivers in the specified application", py::arg("theApp"));
	cls_XmlDrivers.def_static("AttributeDrivers_", (opencascade::handle<XmlMDF_ADriverTable> (*)(const opencascade::handle<CDM_MessageDriver> &)) &XmlDrivers::AttributeDrivers, "None", py::arg("theMsgDriver"));


}
