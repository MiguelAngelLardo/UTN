namespace PRACTICA_7
{
    partial class Form1
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
            this.btnNegrita = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.btnSubrayado = new System.Windows.Forms.Button();
            this.btnCursiva = new System.Windows.Forms.Button();
            this.btnCentrado = new System.Windows.Forms.Button();
            this.txtTamanio = new System.Windows.Forms.TextBox();
            this.btnGuardar = new System.Windows.Forms.Button();
            this.btnAbrir = new System.Windows.Forms.Button();
            this.rtxtEditor = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // btnNegrita
            // 
            this.btnNegrita.Location = new System.Drawing.Point(125, 62);
            this.btnNegrita.Name = "btnNegrita";
            this.btnNegrita.Size = new System.Drawing.Size(75, 23);
            this.btnNegrita.TabIndex = 0;
            this.btnNegrita.Text = "Negrita";
            this.btnNegrita.UseVisualStyleBackColor = true;
            this.btnNegrita.Click += new System.EventHandler(this.btnNegrita_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(211, 103);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(102, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "Tamaño Fuente";
            // 
            // btnSubrayado
            // 
            this.btnSubrayado.Location = new System.Drawing.Point(250, 62);
            this.btnSubrayado.Name = "btnSubrayado";
            this.btnSubrayado.Size = new System.Drawing.Size(75, 23);
            this.btnSubrayado.TabIndex = 2;
            this.btnSubrayado.Text = "Subrayado";
            this.btnSubrayado.UseVisualStyleBackColor = true;
            this.btnSubrayado.Click += new System.EventHandler(this.btnSubrayado_Click);
            // 
            // btnCursiva
            // 
            this.btnCursiva.Location = new System.Drawing.Point(367, 62);
            this.btnCursiva.Name = "btnCursiva";
            this.btnCursiva.Size = new System.Drawing.Size(75, 23);
            this.btnCursiva.TabIndex = 3;
            this.btnCursiva.Text = "Cursiva";
            this.btnCursiva.UseVisualStyleBackColor = true;
            this.btnCursiva.Click += new System.EventHandler(this.btnCursiva_Click);
            // 
            // btnCentrado
            // 
            this.btnCentrado.Location = new System.Drawing.Point(495, 62);
            this.btnCentrado.Name = "btnCentrado";
            this.btnCentrado.Size = new System.Drawing.Size(75, 23);
            this.btnCentrado.TabIndex = 4;
            this.btnCentrado.Text = "Centrado";
            this.btnCentrado.UseVisualStyleBackColor = true;
            this.btnCentrado.Click += new System.EventHandler(this.btnCentrado_Click);
            // 
            // txtTamanio
            // 
            this.txtTamanio.Location = new System.Drawing.Point(332, 103);
            this.txtTamanio.Name = "txtTamanio";
            this.txtTamanio.Size = new System.Drawing.Size(100, 22);
            this.txtTamanio.TabIndex = 5;
            this.txtTamanio.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtTamanio_KeyPress);
            this.txtTamanio.Validated += new System.EventHandler(this.txtTamanio_Validated);
            // 
            // btnGuardar
            // 
            this.btnGuardar.Location = new System.Drawing.Point(238, 382);
            this.btnGuardar.Name = "btnGuardar";
            this.btnGuardar.Size = new System.Drawing.Size(75, 23);
            this.btnGuardar.TabIndex = 7;
            this.btnGuardar.Text = "Guardar";
            this.btnGuardar.UseVisualStyleBackColor = true;
            this.btnGuardar.Click += new System.EventHandler(this.btnGuardar_Click);
            // 
            // btnAbrir
            // 
            this.btnAbrir.Location = new System.Drawing.Point(334, 382);
            this.btnAbrir.Name = "btnAbrir";
            this.btnAbrir.Size = new System.Drawing.Size(75, 23);
            this.btnAbrir.TabIndex = 8;
            this.btnAbrir.Text = "Abrir";
            this.btnAbrir.UseVisualStyleBackColor = true;
            this.btnAbrir.Click += new System.EventHandler(this.btnAbrir_Click);
            // 
            // rtxtEditor
            // 
            this.rtxtEditor.Location = new System.Drawing.Point(29, 139);
            this.rtxtEditor.Name = "rtxtEditor";
            this.rtxtEditor.Size = new System.Drawing.Size(601, 202);
            this.rtxtEditor.TabIndex = 9;
            this.rtxtEditor.Text = "";
            this.rtxtEditor.LinkClicked += new System.Windows.Forms.LinkClickedEventHandler(this.rtxtEditor_LinkClicked);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(658, 450);
            this.Controls.Add(this.rtxtEditor);
            this.Controls.Add(this.btnAbrir);
            this.Controls.Add(this.btnGuardar);
            this.Controls.Add(this.txtTamanio);
            this.Controls.Add(this.btnCentrado);
            this.Controls.Add(this.btnCursiva);
            this.Controls.Add(this.btnSubrayado);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnNegrita);
            this.Name = "Form1";
            this.Text = "RichTextBox";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnNegrita;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnSubrayado;
        private System.Windows.Forms.Button btnCursiva;
        private System.Windows.Forms.Button btnCentrado;
        private System.Windows.Forms.TextBox txtTamanio;
        private System.Windows.Forms.Button btnGuardar;
        private System.Windows.Forms.Button btnAbrir;
        private System.Windows.Forms.RichTextBox rtxtEditor;
    }
}

