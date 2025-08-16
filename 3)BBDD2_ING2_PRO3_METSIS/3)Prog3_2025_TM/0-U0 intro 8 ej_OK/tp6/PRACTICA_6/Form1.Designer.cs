namespace PRACTICA_6
{
    partial class fmrRbtnCb
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.cbProgramador = new System.Windows.Forms.CheckBox();
            this.txtNombre = new System.Windows.Forms.TextBox();
            this.btnOk = new System.Windows.Forms.Button();
            this.gbSexo = new System.Windows.Forms.GroupBox();
            this.rbMujer = new System.Windows.Forms.RadioButton();
            this.rbHombre = new System.Windows.Forms.RadioButton();
            this.label3 = new System.Windows.Forms.Label();
            this.tbSalida = new System.Windows.Forms.TextBox();
            this.gbSexo.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(60, 56);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(56, 16);
            this.label1.TabIndex = 0;
            this.label1.Text = "Nombre";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(60, 98);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(87, 16);
            this.label2.TabIndex = 1;
            this.label2.Text = "Programador";
            // 
            // cbProgramador
            // 
            this.cbProgramador.AutoSize = true;
            this.cbProgramador.Location = new System.Drawing.Point(168, 97);
            this.cbProgramador.Name = "cbProgramador";
            this.cbProgramador.Size = new System.Drawing.Size(18, 17);
            this.cbProgramador.TabIndex = 2;
            this.cbProgramador.UseVisualStyleBackColor = true;
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(168, 56);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(292, 22);
            this.txtNombre.TabIndex = 3;
            this.txtNombre.Validating += new System.ComponentModel.CancelEventHandler(this.txtNombre_Validating);
            // 
            // btnOk
            // 
            this.btnOk.Location = new System.Drawing.Point(485, 55);
            this.btnOk.Name = "btnOk";
            this.btnOk.Size = new System.Drawing.Size(75, 23);
            this.btnOk.TabIndex = 4;
            this.btnOk.Text = "OK";
            this.btnOk.UseVisualStyleBackColor = true;
            this.btnOk.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // gbSexo
            // 
            this.gbSexo.Controls.Add(this.rbHombre);
            this.gbSexo.Controls.Add(this.rbMujer);
            this.gbSexo.Location = new System.Drawing.Point(63, 135);
            this.gbSexo.Name = "gbSexo";
            this.gbSexo.Size = new System.Drawing.Size(397, 100);
            this.gbSexo.TabIndex = 5;
            this.gbSexo.TabStop = false;
            this.gbSexo.Text = "Sexo";
            // 
            // rbMujer
            // 
            this.rbMujer.AutoSize = true;
            this.rbMujer.Location = new System.Drawing.Point(309, 42);
            this.rbMujer.Name = "rbMujer";
            this.rbMujer.Size = new System.Drawing.Size(61, 20);
            this.rbMujer.TabIndex = 0;
            this.rbMujer.TabStop = true;
            this.rbMujer.Text = "Mujer";
            this.rbMujer.UseVisualStyleBackColor = true;
            // 
            // rbHombre
            // 
            this.rbHombre.AutoSize = true;
            this.rbHombre.Location = new System.Drawing.Point(67, 42);
            this.rbHombre.Name = "rbHombre";
            this.rbHombre.Size = new System.Drawing.Size(77, 20);
            this.rbHombre.TabIndex = 1;
            this.rbHombre.TabStop = true;
            this.rbHombre.Text = "Hombre";
            this.rbHombre.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(60, 259);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(46, 16);
            this.label3.TabIndex = 6;
            this.label3.Text = "Salida";
            // 
            // tbSalida
            // 
            this.tbSalida.Location = new System.Drawing.Point(63, 278);
            this.tbSalida.Multiline = true;
            this.tbSalida.Name = "tbSalida";
            this.tbSalida.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tbSalida.Size = new System.Drawing.Size(397, 94);
            this.tbSalida.TabIndex = 7;
            // 
            // fmrRbtnCb
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(605, 450);
            this.Controls.Add(this.tbSalida);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.gbSexo);
            this.Controls.Add(this.btnOk);
            this.Controls.Add(this.txtNombre);
            this.Controls.Add(this.cbProgramador);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "fmrRbtnCb";
            this.Text = "RadioButton y CheckBox";
            this.Load += new System.EventHandler(this.fmrRbtnCb_Load);
            this.gbSexo.ResumeLayout(false);
            this.gbSexo.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.CheckBox cbProgramador;
        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.Button btnOk;
        private System.Windows.Forms.GroupBox gbSexo;
        private System.Windows.Forms.RadioButton rbHombre;
        private System.Windows.Forms.RadioButton rbMujer;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox tbSalida;
    }
}

