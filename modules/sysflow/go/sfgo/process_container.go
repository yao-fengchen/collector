// Code generated by github.com/actgardner/gogen-avro/v7. DO NOT EDIT.
/*
 * SOURCE:
 *     SysFlow.avsc
 */
package sfgo

import (
	"io"

	"github.com/actgardner/gogen-avro/v7/compiler"
	"github.com/actgardner/gogen-avro/v7/container"
	"github.com/actgardner/gogen-avro/v7/vm"
)

func NewProcessWriter(writer io.Writer, codec container.Codec, recordsPerBlock int64) (*container.Writer, error) {
	str := NewProcess()
	return container.NewWriter(writer, codec, recordsPerBlock, str.Schema())
}

// container reader
type ProcessReader struct {
	r io.Reader
	p *vm.Program
}

func NewProcessReader(r io.Reader) (*ProcessReader, error) {
	containerReader, err := container.NewReader(r)
	if err != nil {
		return nil, err
	}

	t := NewProcess()
	deser, err := compiler.CompileSchemaBytes([]byte(containerReader.AvroContainerSchema()), []byte(t.Schema()))
	if err != nil {
		return nil, err
	}

	return &ProcessReader{
		r: containerReader,
		p: deser,
	}, nil
}

func (r ProcessReader) Read() (*Process, error) {
	t := NewProcess()
	err := vm.Eval(r.r, r.p, t)
	return t, err
}
