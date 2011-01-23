// Copyright (c) 2010, Jérôme Velut
// All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER ``AS IS'' AND ANY EXPRESS 
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN 
// NO EVENT SHALL THE COPYRIGHT OWNER BE LIABLE FOR ANY DIRECT, INDIRECT, 
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
// OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "vtkFrenetSerretFrame.h"

#include "vtkXMLPolyDataReader.h"
#include "vtkMetaImageReader.h"
#include "vtkXMLPolyDataWriter.h"
#include "vtkSmartPointer.h"

int main(int argc, char** argv )
{
    if( argc == 1)
    {
       cout << "\ttestFrenetSerretFrame [spline]"
            << endl;
       cout << "[spline] is an xml vtkPolyData file" << endl;
       return( 0 );
    }

    vtkSmartPointer<vtkXMLPolyDataReader> splineReader;
    splineReader = vtkSmartPointer<vtkXMLPolyDataReader>::New( );
    splineReader->SetFileName( argv[1] );
 
    vtkSmartPointer<vtkFrenetSerretFrame> frenetSerretFilter;
    frenetSerretFilter = vtkSmartPointer<vtkFrenetSerretFrame>::New( );
    
    frenetSerretFilter->SetInputConnection( splineReader->GetOutputPort( ) );
    frenetSerretFilter->Update( );

    vtkSmartPointer<vtkXMLPolyDataWriter> splineWriter;
    splineWriter = vtkSmartPointer<vtkXMLPolyDataWriter>::New( );
    splineWriter->SetFileName( "output.vtp"  );
    splineWriter->SetInputConnection( frenetSerretFilter->GetOutputPort() );
    splineWriter->Write( );
    
}
