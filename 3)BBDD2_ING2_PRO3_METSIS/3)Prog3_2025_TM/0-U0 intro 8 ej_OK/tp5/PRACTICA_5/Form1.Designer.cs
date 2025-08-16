namespace PRACTICA_5
{
    partial class fDatosPersonales
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.tbApelido = new System.Windows.Forms.TextBox();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.lbApellido = new System.Windows.Forms.Label();
            this.lbNombre = new System.Windows.Forms.Label();
            this.tbNombre = new System.Windows.Forms.TextBox();
            this.lbEdad = new System.Windows.Forms.Label();
            this.tbEdad = new System.Windows.Forms.TextBox();
            this.lbDireccion = new System.Windows.Forms.Label();
            this.tbDireccion = new System.Windows.Forms.TextBox();
            this.lbResultado = new System.Windows.Forms.Label();
            this.tbResultado = new System.Windows.Forms.TextBox();
            this.btnAceptar = new System.Windows.Forms.Button();
            this.btnCancelar = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // tbApelido
            // 
            this.tbApelido.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.tbApelido.Location = new System.Drawing.Point(305, 72);
            this.tbApelido.MaxLength = 8;
            this.tbApelido.Name = "tbApelido";
            this.tbApelido.Size = new System.Drawing.Size(269, 22);
            this.tbApelido.TabIndex = 0;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // lbApellido
            // 
            this.lbApellido.AutoSize = true;
            this.lbApellido.Location = new System.Drawing.Point(196, 75);
            this.lbApellido.Name = "lbApellido";
            this.lbApellido.Size = new System.Drawing.Size(71, 16);
            this.lbApellido.TabIndex = 2;
            this.lbApellido.Text = "APELLIDO";
            // 
            // lbNombre
            // 
            this.lbNombre.AutoSize = true;
            this.lbNombre.Location = new System.Drawing.Point(196, 112);
            this.lbNombre.Name = "lbNombre";
            this.lbNombre.Size = new System.Drawing.Size(66, 16);
            this.lbNombre.TabIndex = 4;
            this.lbNombre.Text = "NOMBRE";
            // 
            // tbNombre
            // 
            this.tbNombre.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.tbNombre.Location = new System.Drawing.Point(305, 112);
            this.tbNombre.MaxLength = 8;
            this.tbNombre.Name = "tbNombre";
            this.tbNombre.Size = new System.Drawing.Size(269, 22);
            this.tbNombre.TabIndex = 3;
            // 
            // lbEdad
            // 
            this.lbEdad.AutoSize = true;
            this.lbEdad.Location = new System.Drawing.Point(196, 157);
            this.lbEdad.Name = "lbEdad";
            this.lbEdad.Size = new System.Drawing.Size(45, 16);
            this.lbEdad.TabIndex = 6;
            this.lbEdad.Text = "EDAD";
            // 
            // tbEdad
            // 
            this.tbEdad.Location = new System.Drawing.Point(305, 157);
            this.tbEdad.MaxLength = 8;
            this.tbEdad.Name = "tbEdad";
            this.tbEdad.Size = new System.Drawing.Size(100, 22);
            this.tbEdad.TabIndex = 5;
            this.tbEdad.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.tbEdad_KeyPress);
            // 
            // lbDireccion
            // 
            this.lbDireccion.AutoSize = true;
            this.lbDireccion.Location = new System.Drawing.Point(196, 202);
            this.lbDireccion.Name = "lbDireccion";
            this.lbDireccion.Size = new System.Drawing.Size(80, 16);
            this.lbDireccion.TabIndex = 8;
            this.lbDireccion.Text = "DIRECCION";
            // 
            // tbDireccion
            // 
            this.tbDireccion.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.tbDireccion.Location = new System.Drawing.Point(305, 199);
            this.tbDireccion.MaxLength = 8;
            this.tbDireccion.Name = "tbDireccion";
            this.tbDireccion.Size = new System.Drawing.Size(269, 22);
            this.tbDireccion.TabIndex = 7;
            // 
            // lbResultado
            // 
            this.lbResultado.AutoSize = true;
            this.lbResultado.Location = new System.Drawing.Point(196, 244);
            this.lbResultado.Name = "lbResultado";
            this.lbResultado.Size = new System.Drawing.Size(90, 16);
            this.lbResultado.TabIndex = 10;
            this.lbResultado.Text = "RESULTADO";
            // 
            // tbResultado
            // 
            this.tbResultado.Location = new System.Drawing.Point(199, 289);
            this.tbResultado.Multiline = true;
            this.tbResultado.Name = "tbResultado";
            this.tbResultado.Size = new System.Drawing.Size(340, 97);
            this.tbResultado.TabIndex = 9;
            // 
            // btnAceptar
            // 
            this.btnAceptar.Location = new System.Drawing.Point(250, 392);
            this.btnAceptar.Name = "btnAceptar";
            this.btnAceptar.Size = new System.Drawing.Size(84, 28);
            this.btnAceptar.TabIndex = 11;
            this.btnAceptar.Text = "Aceptar";
            this.btnAceptar.UseVisualStyleBackColor = true;
            this.btnAceptar.Click += new System.EventHandler(this.btnAceptar_Click);
            // 
            // btnCancelar
            // 
            this.btnCancelar.Location = new System.Drawing.Point(408, 392);
            this.btnCancelar.Name = "btnCancelar";
            this.btnCancelar.Size = new System.Drawing.Size(84, 28);
            this.btnCancelar.TabIndex = 12;
            this.btnCancelar.Text = "Cancelar";
            this.btnCancelar.UseVisualStyleBackColor = true;
            this.btnCancelar.Click += new System.EventHandler(this.btnCancelar_Click);
            // 
            // fDatosPersonales
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 475);
            this.Controls.Add(this.btnCancelar);
            this.Controls.Add(this.btnAceptar);
            this.Controls.Add(this.lbResultado);
            this.Controls.Add(this.tbResultado);
            this.Controls.Add(this.lbDireccion);
            this.Controls.Add(this.tbDireccion);
            this.Controls.Add(this.lbEdad);
            this.Controls.Add(this.tbEdad);
            this.Controls.Add(this.lbNombre);
            this.Controls.Add(this.tbNombre);
            this.Controls.Add(this.lbApellido);
            this.Controls.Add(this.tbApelido);
            this.Name = "fDatosPersonales";
            this.Text = "Datos Personales";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbApelido;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.Label lbApellido;
        private System.Windows.Forms.Label lbNombre;
        private System.Windows.Forms.TextBox tbNombre;
        private System.Windows.Forms.Label lbEdad;
        private System.Windows.Forms.TextBox tbEdad;
        private System.Windows.Forms.Label lbDireccion;
        private System.Windows.Forms.TextBox tbDireccion;
        private System.Windows.Forms.Label lbResultado;
        private System.Windows.Forms.TextBox tbResultado;
        private System.Windows.Forms.Button btnAceptar;
        private System.Windows.Forms.Button btnCancelar;
    }
}

